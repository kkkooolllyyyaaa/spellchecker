//
// Created by Цыпандин Николай Петрович on 26.03.2022.
//

#ifndef INC_01_SPELLCHECKER_SPELLCHECKER_H
#define INC_01_SPELLCHECKER_SPELLCHECKER_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

class SpellChecker {
private:
    struct wordIndex {
        double index;
        std::string word;
    };
    std::unordered_map<std::string, int> digramCnt;
    std::unordered_map<std::string, int> trigramCnt;
    std::unordered_map<std::string, std::unordered_set<std::string>> wordTrigrams;
    std::vector<wordIndex> wordIndexes;


    static bool wordIndexComparator(const wordIndex &i1, const wordIndex &i2);

    static bool nGramsComparator(const std::pair<std::string, int> &ng1,
                                 const std::pair<std::string, int> &ng2);

    double calculateWordIndex(const std::string &word);

    double calculateLittleIndex(const std::string &trigram);

    double nFunction(const std::string &nGram);

public:
    void processWords(const std::vector<std::string> &words);

    void calculateIndexes();

    void sortWordTrigrams();

    int getUniqueWordsCnt();

    std::vector<std::string> getLikelyWords(double N);

    std::vector<std::pair<std::string, int>> getTrigrams();

    std::vector<std::pair<std::string, int>> getDigrams();
};


#endif //INC_01_SPELLCHECKER_SPELLCHECKER_H
