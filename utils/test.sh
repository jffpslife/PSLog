#!/bin/bash

FILECOUNT=$(find $THISDIR/$MYDIRNAME/tests -type f | wc -l)
echo $FILECOUNT
LASTIDX=$((FILECOUNT - 1))
echo $LASTIDX

for (( i=0; i<=$LASTIDX; i++)); do
	echo "Test $i"
	cat $THISDIR/$MYDIRNAME/tests/$i.txt | $THISDIR/$MYDIRNAME/$MYNAME
done
