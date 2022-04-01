//
// Created by Цыпандин Николай Петрович on 30.03.2022.
//

#ifndef INC_01_SPELLCHECKER_FILEREADER_H
#define INC_01_SPELLCHECKER_FILEREADER_H

#include <string>
#include <fstream>

class FileReader {
private:
    std::ifstream &in;
public:
    explicit FileReader(std::ifstream &ifstream);

    std::string readLine();
};

#endif //INC_01_SPELLCHECKER_FILEREADER_H
