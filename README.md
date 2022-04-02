# Spellchecker project
stack:
+ C++17
+ CMake

# Build
1) Run bash script
   + ./build.sh
   
     Make sure you have execution rights
   + Script will navigate you through program build and execution
2) Manual project build
   + mkdir build && cd build
   + cmake -DCMAKE_BUILD_TYPE=[BUILD_TYPE] 
   
     for example: cmake -DCMAKE_BUILD_TYPE=Release

     available build types: [Debug], [Release], [Sanitized]
   + make
   + ./01-spellchecker [filepath]

     It is better to use the absolute path to the file