#ifndef ENGINE_H
#define ENGINE_H

#pragma once
#include <string>

void init();                               // Inicialización general del motor
void processCommands(const std::string &command); // Procesa los comandos

#endif
