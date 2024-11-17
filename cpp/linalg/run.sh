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
  build/build/Release/example_1_3
  build/build/Release/example_1_4
  build/build/Release/example_1_7
}

run_all
