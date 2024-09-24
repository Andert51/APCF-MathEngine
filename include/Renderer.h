#ifndef RENDERER_H
#define RENDERER_H

#pragma once

void setupOpenGL(); // Configurar OpenGL (mover esto aquí)
void render();      // Función que realizará el renderizado de la escena
void renderScene(); // Función donde definiremos la lógica de renderizado de objetos
void drawTriangle2D(); // Dibujar un triángulo en 2D
void drawLine2D();     // Dibujar una línea en 2D
void drawCube3D();     // Dibujar un cubo en 3D

#endif
