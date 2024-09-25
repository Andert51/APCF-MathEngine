#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"
#include <iostream>

void setupOpenGL()
{
    glewInit();
    glEnable(GL_DEPTH_TEST);                           // Habilitar pruebas de profundidad para 3D
    glDepthFunc(GL_LESS);                              // Función de profundidad
    glEnable(GL_CULL_FACE);                            // Habilitar culling para optimización
    glCullFace(GL_BACK);                               // Culling de las caras traseras
    glEnable(GL_BLEND);                                // Habilitar transparencia
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Función de mezcla
}

void renderScene()
{
    // Este método ahora solo llama a la figura específica según el comando
    extern std::string currentCommand;

    // Clear the buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (currentCommand == "triangle")
    {
        drawTriangle2D();
    }
    else if (currentCommand == "line")
    {
        drawLine2D();
    }
    else if (currentCommand == "cube")
    {
        drawCube3D();
    }
    else
    {
        std::cerr << "No valid object to render" << std::endl;
    }
}

void drawTriangle2D()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Proyección ortogonal
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_TRIANGLES);       // Iniciar el modo de dibujo para triángulos
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); // Azul
    glVertex2f(0.0f, 0.5f);
    glEnd();
}

void drawLine2D()
{
    glBegin(GL_LINES);           // Iniciar el modo de dibujo para líneas
    glColor3f(1.0f, 1.0f, 1.0f); // Blanco
    glVertex2f(-0.8f, 0.0f);
    glVertex2f(0.8f, 0.0f);
    glEnd();
}

void drawCube3D()
{
    glBegin(GL_QUADS); // Dibujo con cuadrados (cada cara del cubo)

    // Cara frontal
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    // Cara trasera
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    // Otras caras se agregan similarmente

    glEnd();
}
