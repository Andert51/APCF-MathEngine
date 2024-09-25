#include "Engine.h"
#include "Renderer.h"
#include <iostream>
#include <string>

std::string currentCommand = "triangle"; // Comando predeterminado

void init()
{
    setupOpenGL(); // Configurar OpenGL para renderizado
}

void processCommands(const std::string &command)
{
    if (command == "triangle" || command == "line" || command == "cube")
    {
        currentCommand = command; // Actualizar el comando de renderizado
    }
    else
    {
        std::cerr << "Command not recognized" << std::endl;
    }
}
