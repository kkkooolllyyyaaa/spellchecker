cmake_minimum_required(VERSION 3.20)
project(01-spellchecker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "-std=c++17 -Wall -Werror -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} -O3")
set(CMAKE_CXX_FLAGS_SANITIZED "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,undefined,leak")

mark_as_advanced(
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_SANITIZED
        CMAKE_CXX_FLAGS_RELEASE
)

include_directories(include)
add_executable(01-spellchecker src/main.cpp src/SpellChecker.cpp src/TextCleaner.cpp src/TextCleaner.h src/FileReader.cpp src/FileReader.h src/client_io.cpp src/client_io.h src/EndOfFileException.cpp src/EndOfFileException.h src/Application.cpp include/Application.h)
