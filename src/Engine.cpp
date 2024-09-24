#include "Engine.h"
#include "Renderer.h"
#include <iostream>
#include <string>

std::string currentCommand = "triangle"; // Comando por defecto

void init()
{
    setupOpenGL(); // Inicializa OpenGL
}

void processCommands(const char *command)
{
    std::string input = command;

    if (input == "triangle")
    {
        currentCommand = "triangle";
        std::cout << "Switched to rendering a 2D triangle." << std::endl;
    }
    else if (input == "line")
    {
        currentCommand = "line";
        std::cout << "Switched to rendering a 2D line." << std::endl;
    }
    else if (input == "cube")
    {
        currentCommand = "cube";
        std::cout << "Switched to rendering a 3D cube." << std::endl;
    }
    else
    {
        std::cerr << "Unknown command: " << command << std::endl;
    }
}
