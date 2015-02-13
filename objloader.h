#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <vector>
#include <stdio.h>
#include <cstring>
#include "glm/glm/glm.hpp"

class Objloader {
public:
    //! Default constructor
    Objloader();

    /*! It loads an obg file to read the file path, and write the data into out_vertices, out_uvs, and out_normals.
     * If something goes wrong, it returns false.
     * \ sa out_vertices returns list of vertex
     * \ sa out_uvs returns points in parameter space of curve or surface
     * \ sa out_normals retruns list of normals
     */
    bool LoadObj3D(
        const char * path,
        std::vector<glm::vec4> & out_vertices,
        std::vector<glm::vec3> & out_uvs,
        std::vector<glm::vec4> & out_normals
    );
};

#endif // OBJLOADER_H
