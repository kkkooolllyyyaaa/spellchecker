//
// Created by Цыпандин Николай Петрович on 01.04.2022.
//

#ifndef INC_01_SPELLCHECKER_APPLICATION_H
#define INC_01_SPELLCHECKER_APPLICATION_H

#include <string>
#include "../src/SpellChecker.h"

class Application {
private:
    std::string filename;
    double N;

    void interactiveMode(SpellChecker spellChecker);

public:
    Application(std::string filename, double N);

    void start();

    void setN(double Nvalue);

    double getN();
};


#endif //INC_01_SPELLCHECKER_APPLICATION_H
