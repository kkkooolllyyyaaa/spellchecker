cmake_minimum_required(VERSION 3.20)
project(01-spellchecker)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(01-spellchecker src/main.cpp src/SpellChecker.cpp)
