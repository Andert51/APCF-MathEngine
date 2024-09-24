#include "Engine.h"
#include "Renderer.h"
#include "exprtk.hpp"
#include <iostream>
#include <string>

typedef double T;
typedef exprtk::symbol_table<T> symbol_table_t;
typedef exprtk::expression<T> expression_t;
typedef exprtk::parser<T> parser_t;

std::string currentCommand = "triangle"; // Comando por defecto

void init()
{
    // Inicialización del motor, se puede expandir según sea necesario.
    setupOpenGL(); // Mantén esta llamada aquí para inicializar el renderizado
}

// void processCommands(const char *command)
// {
//     std::string input = command;

//     symbol_table_t symbol_table;
//     expression_t expression;
//     expression.register_symbol_table(symbol_table);

//     parser_t parser;
//     if (!parser.compile(input, expression))
//     {
//         std::cerr << "Error parsing command: " << command << std::endl;
//     }
//     else
//     {
//         T result = expression.value();
//         std::cout << "Result: " << result << std::endl;
//     }
// }

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

void renderScene()
{
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
}