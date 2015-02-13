#define _CRT_SECURE_NO_WARNINGS

#include "objloader.h"

Objloader::Objloader()
{
}

bool Objloader::LoadObj3D(const char * path,
    std::vector<glm::vec4> & out_vertices,
    std::vector<glm::vec3> & out_uvs,
    std::vector<glm::vec4> &out_normals
){
    printf("Loading OBJ file %s...\n", path);

    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec4> temp_vertices;
    std::vector<glm::vec3> temp_uvs;
    std::vector<glm::vec4> temp_normals;

    FILE * file = fopen(path, "r");
    if( file == NULL ){
        printf("Impossible to open the file !\n");
        return false;
    }

    while( 1 ){
        char lineHeader[128];
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break;

        if ( strcmp( lineHeader, "v" ) == 0 ){
            glm::vec4 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            vertex.w = 1.0f;
            temp_vertices.push_back(vertex);
        }else if ( strcmp( lineHeader, "vt" ) == 0 ){
            glm::vec3 uv;
            int matches = fscanf(file, "%f %f %f\n", &uv.x, &uv.y, &uv.z );
            if (matches == 2)
                uv.z = 0.0f;
            temp_uvs.push_back(uv);
        }else if ( strcmp( lineHeader, "vn" ) == 0 ){
            glm::vec4 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
            normal.w = 1.0f;
            temp_normals.push_back(normal);
        }else if ( strcmp( lineHeader, "f" ) == 0 ){
            unsigned int vertexIndex[4], uvIndex[4], normalIndex[4];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                    &vertexIndex[2], &uvIndex[2], &normalIndex[2], &vertexIndex[3], &uvIndex[3], &normalIndex[3] );
            if (matches == 9 || matches == 12){
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                uvIndices    .push_back(uvIndex[0]);
                uvIndices    .push_back(uvIndex[1]);
                uvIndices    .push_back(uvIndex[2]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);
                if (matches == 12) {
                    vertexIndices.push_back(vertexIndex[0]);
                    vertexIndices.push_back(vertexIndex[2]);
                    vertexIndices.push_back(vertexIndex[3]);
                    uvIndices    .push_back(uvIndex[0]);
                    uvIndices    .push_back(uvIndex[2]);
                    uvIndices    .push_back(uvIndex[3]);
                    normalIndices.push_back(normalIndex[0]);
                    normalIndices.push_back(normalIndex[2]);
                    normalIndices.push_back(normalIndex[3]);
                }
            } else {
                printf("File can't be read by our simple parser :-( Try exporting with other options\n");
                return false;
            }

        }else{
            // Probably a comment, eat up the rest of the line
            char stupidBuffer[1000];
            fgets(stupidBuffer, 1000, file);
        }
    }

    // For each triangle
    for (size_t i=0; i<vertexIndices.size(); i++){
        glm::vec4 vertex = temp_vertices[vertexIndices[i]-1];
        glm::vec3 uv = temp_uvs[uvIndices[i]-1];
        glm::vec4 normal = temp_normals[normalIndices[i]-1];

        out_vertices.push_back(vertex);
        out_uvs     .push_back(uv);
        out_normals .push_back(normal);
    }

    return true;
}
