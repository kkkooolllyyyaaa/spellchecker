//
// Created by Цыпандин Николай Петрович on 01.04.2022.
//

#include "EndOfFileException.h"
#include <string>

EndOfFileException::EndOfFileException(const std::string &message) {
    this->message = message;
}

std::string EndOfFileException::getMessage() {
    return message;
}
