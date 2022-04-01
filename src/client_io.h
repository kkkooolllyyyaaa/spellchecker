//
// Created by Цыпандин Николай Петрович on 01.04.2022.
//

#ifndef INC_01_SPELLCHECKER_CLIENT_IO_H
#define INC_01_SPELLCHECKER_CLIENT_IO_H
#define ERROR_CODE 1

#include <string>

void info(const std::string &message);

void error(const std::string &message);

std::string readCommand();

double readDouble();

void exitProgram();

void printLine();

#endif //INC_01_SPELLCHECKER_CLIENT_IO_H
