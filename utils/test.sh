#!/bin/bash

N=$1
N=$((N))

BIN=$MYDIRNAME/$MYNAME
TESTDIR=$MYDIRNAME/tests

for (( i=0; i<$N; i++)); do
	echo "Test $i"
	cat $TESTDIR/in-$i.txt | $BIN > $TESTDIR/res-$i.txt
  diff -Z $TESTDIR/res-$i.txt $TESTDIR/out-$i.txt
done
