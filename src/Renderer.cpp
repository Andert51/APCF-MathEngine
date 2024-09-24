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
    // Aquí puedes cambiar qué objeto se va a renderizar
    drawTriangle2D();
    drawLine2D();
    drawCube3D();
}

void drawTriangle2D()
{
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

    // Otras caras...
    // Puedes agregar las otras caras con colores diferentes si lo deseas
    glEnd();
}
