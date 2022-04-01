//
// Created by Цыпандин Николай Петрович on 26.03.2022.
//

#include "Application.h"
#include <string>

#define N_DEFAULT 8.0

int main(int argc, char **argv) {
//    if (argc != 2) {
//        infoUsageAndExit();
//    }
    std::string filepath = "/Users/tsypk/CLionProjects/01-spellchecker/files/test.txt";
    double N = N_DEFAULT;

    auto *application = new Application(filepath, N);
    application->start();
}