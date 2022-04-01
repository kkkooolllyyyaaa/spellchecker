cmake_minimum_required(VERSION 3.20)
project(01-spellchecker)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(01-spellchecker src/main.cpp src/SpellChecker.cpp src/TextCleaner.cpp src/TextCleaner.h src/FileReader.cpp src/FileReader.h src/client_io.cpp src/client_io.h src/EndOfFileException.cpp src/EndOfFileException.h src/Application.cpp include/Application.h)
