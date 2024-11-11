#!/usr/bin/env bash

set -ex

run() {
  executable=$1
  if [[ -z $executable ]]; then
    echo "No file specfied to execute"
    exit -1
  fi
  $executable
}

run_all() {
  build/build/Release/example1_boost
  build/build/Release/example1_armadillo

  build/build/Release/example2_boost
  build/build/Release/example2_armadillo

  build/build/Release/example3_boost
  build/build/Release/example3_armadillo
}

run_all
