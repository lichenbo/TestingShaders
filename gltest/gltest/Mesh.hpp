//
//  Mesh.hpp
//  gltest
//
//  Created by Chenbo Li on 2/24/16.
//  Copyright © 2016 binarythink. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#ifdef _WIN32
	#include <GL/glew.h>
#else
	#include <OpenGL/gl3.h>
#endif

class ShaderProgram;

class Mesh
{
public:
    Mesh();
    void Load(const char* filename);
    void Draw(ShaderProgram* shader);
private:
    GLuint vao; // contains multiple vbos
    int numberOfVertices;
    
    // Buffers
    GLuint vbo_coord; // buffer stores vertices info
    GLuint vbo_normal; // buffer stores normal info
        
};


#endif /* Mesh_hpp */