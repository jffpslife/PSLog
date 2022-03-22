#!/bin/bash

set -e

# Currently supported platforms
PLATFORMS=("bj", "cf")

if [[ "bj" == $MYPLATFORM ]]; then
  mkdir -p $MYDIRNAME
  cp $THISDIR/templates/bj.cpp $MYDIRNAME/$MYNAME.cpp

  mkdir -p $THISDIR/cur/tests
elif [[ "cf" == $MYPLATFORM ]]; then
  mkdir -p $MYDIRNAME
  cp $THISDIR/templates/cf.cpp $MYDIRNAME/$MYNAME.cpp

  mkdir -p $THISDIR/cur/tests
else
  mkdir -p $MYDIRNAME
  cp $THISDIR/templates/other.cpp $MYDIRNAME/$MYNAME.cpp

  mkdir -p $MYDIRNAME/tests
fi
