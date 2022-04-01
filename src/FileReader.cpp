//
// Created by Цыпандин Николай Петрович on 30.03.2022.
//

#include "FileReader.h"
#include "EndOfFileException.h"
#include <fstream>

std::string FileReader::readLine() {
    if (in.eof())
        throw EndOfFileException("End of file, reading is completed...");
    if (!in)
        throw std::invalid_argument("Invalid file");
    if (!in.is_open())
        throw std::logic_error("File is closed");
    std::string line;
    getline(in, line);
    return line;
}

FileReader::FileReader(std::ifstream &ifstream) : in(ifstream) {}
