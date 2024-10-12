#!/usr/bin/env bash

set -ex

build/build/Release/example1_boost
build/build/Release/example1_armadillo
build/build/Release/example2_boost
build/build/Release/example2_armadillo
