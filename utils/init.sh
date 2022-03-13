#!/bin/bash

set -e

# Currently supported platforms
PLATFORMS=("bj")

mkdir -p $MYDIRNAME
cp $THISDIR/templates/basic.cpp $THISDIR/$MYDIRNAME/$MYNAME.cpp

mkdir -p $THISDIR/$MYDIRNAME/tests
