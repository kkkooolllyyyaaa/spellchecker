//
// Created by Цыпандин Николай Петрович on 01.04.2022.
//

#include "Application.h"
#include "SpellChecker.h"
#include "TextCleaner.h"
#include "FileReader.h"
#include "client_io.h"
#include "EndOfFileException.h"

#include <utility>
#include <vector>

Application::Application(std::string filename, double N) {
    this->filename = std::move(filename);
    this->N = N;
}

void Application::start() {
    info("Program is starting...");

    SpellChecker spellChecker;

    std::ifstream input(this->filename);
    FileReader fileReader(input);
    std::string line;
    try {
        while (true) {
            line = fileReader.readLine();
            std::vector<std::string> processedWords = TextCleaner::processWords(line);
            spellChecker.processWords(processedWords);
        }
    }
    catch (std::invalid_argument &e) {
        std::string message = "File is unreadable: ";
        message += e.what();
        error(message);
    }
    catch (std::logic_error &e) {
        std::string message = "Logic error! Bad code: ";
        message += e.what();
        error(message);
    } catch (EndOfFileException &e) {
        info(e.getMessage());
        spellChecker.calculateIndexes();
        spellChecker.sortWordTrigrams();
        info("Enter [help] for info");
        interactiveMode(spellChecker);
    }
}

void Application::interactiveMode(SpellChecker spellChecker) {
    try {
        while (true) {
            printLine();
            std::string command = readCommand();
            if (command == "exit") {
                exitProgram();
            } else if (command == "check") {
                std::vector<std::string> likelyBadWords = spellChecker.getLikelyWords(getN());
                info("Total " + std::to_string(likelyBadWords.size()) +
                     " words found for N = " + std::to_string(getN()) + " : ");
                for (std::string &str: likelyBadWords)
                    info(str);
            } else if (command == "set") {
                info("Enter N value:");
                double lastN = getN();
                double value = readDouble();
                setN(value);
                info("N: " + std::to_string(lastN) + " -> " + std::to_string(value));
            } else if (command == "help") {
                info("[exit] - exit program\n"
                     "[check] - print likely incorrect words\n"
                     "[set] - set new N value\n"
                     "[print_di] - print all digrams and their number\n"
                     "[print_tri] - prin all trigrams and their number");
            } else if (command == "print_di") {
                std::vector<std::pair<std::string, int>> digrams = spellChecker.getDigrams();
                info("Total " + std::to_string(digrams.size()) + " digrams found:");
                for (const std::pair<std::string, int> &pr: digrams) {
                    info(pr.first + " : " + std::to_string(pr.second));
                }
            } else if (command == "print_tri") {
                std::vector<std::pair<std::string, int>> trigrams = spellChecker.getTrigrams();
                info("Total " + std::to_string(trigrams.size()) + " trigrams found:");
                for (const std::pair<std::string, int> &pr: trigrams) {
                    info(pr.first + " : " + std::to_string(pr.second));
                }
            } else {
                info("This command doesn't exist!\n"
                     "Enter [help] for info");
            }
        }
    }
    catch (std::exception &e) {
        error("Unexpected error!");
        error(e.what());
        exitProgram();
    }
}

void Application::setN(double Nvalue) {
    this->N = Nvalue;
}

double Application::getN() {
    return N;
}

