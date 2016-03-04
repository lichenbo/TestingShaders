//
//  Engine.cpp
//  gltest
//
//  Created by Chenbo Li on 2/24/16.
//  Copyright © 2016 binarythink. All rights reserved.
//

#include "Engine.hpp"
#include <iostream>

#ifdef _WIN32
	#include <GL/glew.h>
	#include <GL/freeglut.h>
#else
	#include <OpenGL/gl3.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
#endif


Engine::Engine(int argc, char ** argv)
{
    glutInit(&argc, argv);
#ifdef _WIN32
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
#else
	// OSX needs core profile support
    glutInitDisplayMode(GLUT_3_2_CORE_PROFILE|GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
#endif
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);
    glutCreateWindow("OSX GL Demo");
}

void Engine::render(ShaderProgram* shader)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    shader->Bind();
    
    for (auto mesh : meshes)
    {
        mesh->Load();
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    
    shader->Unbind();
    
    glutSwapBuffers();
    glutPostRedisplay();
}

void Engine::addMesh(Mesh* mesh)
{
    meshes.push_back(mesh);
}