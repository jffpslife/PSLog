THISFILE=$(realpath "$0")
# This variable should always be the base path of everything
export THISDIR=$(dirname $THISFILE)

export MYPLATFORM=$1
if [[ "bj" == $MYPLATFORM ]]; then
  export MYNAME=$2
  export MYDIRNAME=$THISDIR/cur
else
  export MYSET=$2
  export MYNAME=$3
  export MYDIRNAME=$THISDIR/$MYSET-$MYNAME
fi

alias ini=$THISDIR/utils/init.sh
alias com=$THISDIR/utils/compile.sh
alias tst=$THISDIR/utils/test.sh
alias vw=$THISDIR/utils/cat.sh
alias cln=$THISDIR/utils/clean.sh
alias sav=$THISDIR/utils/save.sh
