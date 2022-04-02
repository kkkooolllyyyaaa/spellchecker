#!/bin/bash
build_dir="build"
function create_directories() {
  if [ -d "$1" ]; then
    return
  else
    `mkdir $1`
  fi
}
(create_directories $build_dir)

echo "Enter build type: [Debug], [Release], [Sanitized]"
read BUILD_TYPE

if [[ ( $BUILD_TYPE == "Debug") ]]; then
  build_dir=$build_dir"/debug"
elif [[ ($BUILD_TYPE == "Release") ]]; then
    build_dir=$build_dir"/release"
elif [[ ($BUILD_TYPE == "Sanitized") ]]; then
    build_dir=$build_dir"/sanitized"
else
  echo "build type must be in: [Debug], [Release], [Sanitized]"
  exit 0
fi

create_directories $build_dir

cd $build_dir && cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE ../.. && make

echo "[run] - to run the program, else - exit"
read action
echo "---------------------------------------------"
if [[ ( $action == "run") ]]; then
  echo "Enter filepath:"
  read filepath
  echo "---------------------------------------------"
  ./01-spellchecker $filepath
fi
