//
// Created by Цыпандин Николай Петрович on 30.03.2022.
//

#include "TextCleaner.h"

std::string TextCleaner::encloseWord(const std::string &word, char enclosure) {
    return enclosure + word + enclosure;
}

std::string TextCleaner::getWordLower(const std::string &line, size_t pos) {
    size_t len = line.length();
    std::string word;
    while (pos < len && std::isalpha(line[pos])) {
        word.push_back(std::tolower(line[pos]));
        ++pos;
    }
    return word;
}

std::size_t TextCleaner::skipGapPos(const std::string &line, size_t pos) {
    while (pos < line.length() && !std::isalpha(line[pos]))
        ++pos;
    return pos;
}

size_t TextCleaner::splitBySpace(const std::string &line, std::vector<std::string> &words) {
    size_t pos = 0, len = line.length(), wordLen;
    while (pos < len) {
        pos = skipGapPos(line, pos);
        std::string processedWord = getWordLower(line, pos);
        wordLen = processedWord.length();
        if (wordLen > 0)
            words.push_back(encloseWord(processedWord, '.'));
        pos += wordLen;
    }
    return words.size();
}

std::vector<std::string> TextCleaner::processWords(const std::string &line) {
    std::vector<std::string> words;
    splitBySpace(line, words);
    return words;
}
