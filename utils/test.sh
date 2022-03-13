#!/bin/bash

FILECOUNT=$(find $THISDIR/$MYDIRNAME/tests -type f | wc -l)
LASTIDX=$((FILECOUNT - 1))

for (( i=0; i<=$LASTIDX; i++)); do
	echo "Test $i"
	cat $THISDIR/$MYDIRNAME/tests/$i.txt | $THISDIR/$MYDIRNAME/$MYNAME
done
