//
// Created by Цыпандин Николай Петрович on 01.04.2022.
//

#include "client_io.h"
#include <string>
#include <iostream>

void info(const std::string &message) {
    std::cout << message << std::endl;
}

void error(const std::string &message) {
    std::cerr << message << std::endl;
    exit(ERROR_CODE);
}

std::string readCommand() {
    std::string command, res;
    std::getline(std::cin, command);

    size_t i = 0, len = command.length();
    while (i < len && std::isspace(command[i]))
        ++i;

    while (i < len && !std::isspace(command[i])) {
        res.push_back(command[i]);
        ++i;
    }
    return res;
}

double readDouble() {
    double res;
    std::cin >> res;

    std::string stub;
    std::getline(std::cin, stub);
    return res;
}

void exitProgram() {
    info("the Program has completed its work...");
    exit(0);
}


void printLine() {
    const size_t lineLen = 45;
    std::string line;
    for (size_t i = 0; i < lineLen; ++i)
        line.push_back('-');
    info(line);
}