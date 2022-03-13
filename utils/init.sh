#!/bin/bash

set -e

# Currently supported platforms
PLATFORMS=("bj")

mkdir -p $THISDIR/cur
cp $THISDIR/templates/basic.cpp $THISDIR/cur/$MYNAME.cpp

mkdir -p $THISDIR/cur/tests
