//
// Created by Цыпандин Николай Петрович on 26.03.2022.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include "SpellChecker.h"

void SpellChecker::processWords(const std::vector<std::string> &words) {
    for (const std::string &word: words) {
        std::string trigram, digram;
        for (size_t i = 0; i < word.length() - 2; ++i) {
            trigram = word.substr(i, 3);
            trigramCnt[trigram]++;
            digram = word.substr(i, 2);
            digramCnt[digram]++;

            wordTrigrams[word].insert(trigram);
        }
        digram = word.substr(word.length() - 2, 2);
        digramCnt[digram]++;
    }
}

void SpellChecker::calculateIndexes() {
    auto it = wordTrigrams.begin();
    while (it != wordTrigrams.end()) {
        wordIndexes.push_back(
                (wordIndex) {.index = calculateWordIndex(it->first), .word = it->first}
        );
        it++;
    }
}

std::vector<std::string> SpellChecker::getLikelyWords(double N) {
    std::vector<std::string> ans;
    size_t i = 0, sz = wordIndexes.size();
    while (i < sz && wordIndexes[i].index > N) {
        ans.push_back(wordIndexes[i].word.substr(1, wordIndexes[i].word.length() - 2));
        ++i;
    }
    std::sort(ans.begin(), ans.end());
    return ans;
}

void SpellChecker::sortWordTrigrams() {
    std::sort(wordIndexes.begin(), wordIndexes.end(), wordIndexComparator);
}

bool SpellChecker::wordIndexComparator(const wordIndex &i1, const wordIndex &i2) {
    return i1.index > i2.index;
}

double SpellChecker::calculateWordIndex(const std::string &word) {
    double Index = 0, littleIndex;
    std::unordered_set<std::string> trigrams = wordTrigrams[word];
    auto it = trigrams.begin();
    while (it != trigrams.end()) {
        std::string trigram = *it;
        littleIndex = calculateLittleIndex(trigram);
        Index += littleIndex * littleIndex;
        it++;
    }
    return sqrt(Index / double(trigrams.size()));
}

double SpellChecker::calculateLittleIndex(const std::string &trigram) {
    double trigramN = nFunction(trigram);
    double digramN1 = nFunction(trigram.substr(0, 2));
    double digramN2 = nFunction(trigram.substr(1, 2));
    return 1.0 / 2.0 * int(digramN1 + digramN2) - trigramN;
}


double SpellChecker::nFunction(const std::string &nGram) {
    int cnt;
    if (nGram.length() == 2) {
        cnt = digramCnt[nGram];
    } else if (nGram.length() == 3) {
        cnt = trigramCnt[nGram];
    } else {
        throw std::logic_error("Ngram length not equal to 2 or 3");
    }
    return cnt == 1 ? -10.0 : log(cnt - 1);
}

std::vector<std::pair<std::string, int>> SpellChecker::getTrigrams() {
    std::vector<std::pair<std::string, int>> res;
    auto it = trigramCnt.begin();
    while (it != trigramCnt.end()) {
        res.emplace_back(std::make_pair(it->first, it->second));
        it++;
    }
    std::sort(res.begin(), res.end(), nGramsComparator);
    return res;
}

std::vector<std::pair<std::string, int>> SpellChecker::getDigrams() {
    std::vector<std::pair<std::string, int>> res;
    auto it = digramCnt.begin();
    while (it != digramCnt.end()) {
        res.emplace_back(std::make_pair(it->first, it->second));
        it++;
    }
    std::sort(res.begin(), res.end(), nGramsComparator);
    return res;
}

bool SpellChecker::nGramsComparator(const std::pair<std::string, int> &ng1,
                                    const std::pair<std::string, int> &ng2) {
    return ng1.second > ng2.second;
}

int SpellChecker::getUniqueWordsCnt() {
    return wordTrigrams.size();
}
