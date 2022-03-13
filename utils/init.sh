#!/bin/bash

set -e

# Currently supported platforms
PLATFORMS=("bj")

mkdir -p $MYDIRNAME
cp $THISDIR/templates/basic.cpp $MYDIRNAME/$MYNAME.cpp
cd $MYDIRNAME
