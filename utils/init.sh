#!/bin/bash

set -e

# Currently supported platforms
PLATFORMS=("bj")

if [[ "bj" == $MYPLATFORM ]]; do
  mkdir -p $MYDIRNAME
  cp $THISDIR/templates/bj.cpp $MYDIRNAME/$MYNAME.cpp

  mkdir -p $THISDIR/cur/tests
else
  mkdir -p $MYDIRNAME
  cp $THISDIR/templates/other.cpp $MYDIRNAME/$MYNAME.cpp

  mkdir -p $MYDIRNAME/tests
done
