//
// Created by Цыпандин Николай Петрович on 30.03.2022.
//

#ifndef INC_01_SPELLCHECKER_TEXTCLEANER_H
#define INC_01_SPELLCHECKER_TEXTCLEANER_H

#include <string>
#include <vector>

class TextCleaner {
    static std::string encloseWord(const std::string &line, char enclosure);

    static std::string getWordLower(const std::string &line, size_t pos);

    static std::size_t skipGapPos(const std::string &line, size_t pos);

    static size_t splitBySpace(const std::string &line, std::vector<std::string> &words);

public:
    static std::vector<std::string> processWords(const std::string &line);
};

#endif //INC_01_SPELLCHECKER_TEXTCLEANER_H
