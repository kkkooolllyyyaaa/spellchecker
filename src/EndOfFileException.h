//
// Created by Цыпандин Николай Петрович on 01.04.2022.
//

#ifndef INC_01_SPELLCHECKER_ENDOFFILEEXCEPTION_H
#define INC_01_SPELLCHECKER_ENDOFFILEEXCEPTION_H

#include <exception>
#include <string>

class EndOfFileException : public std::exception {
private:
    std::string message;
public:
    explicit EndOfFileException(const std::string &message);

    std::string getMessage();

//    const char * what() const noexcept override;
};


#endif //INC_01_SPELLCHECKER_ENDOFFILEEXCEPTION_H
