//
// Created by Цыпандин Николай Петрович on 26.03.2022.
//

#include "Application.h"
#include <string>
#include <iostream>

#define N_DEFAULT 8.0

void infoUsageAndExit();

int main(int argc, char **argv) {
    if (argc != 2) {
        infoUsageAndExit();
    }

    std::string filepath = argv[1];
    auto *application = new Application(filepath, N_DEFAULT);
    application->start();
}

void infoUsageAndExit() {
    std::cerr << "Usage: ./01-spellchecker [filename]" << std::endl;
    exit(1);
}
