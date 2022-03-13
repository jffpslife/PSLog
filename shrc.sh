THISFILE=$(realpath "$0")
# This variable should always be the base path of everything
export THISDIR=$(dirname $THISFILE)

export MYPLATFORM=$1
export MYNAME=$2
export MYDIRNAME=$MYPLATFORM-$MYNAME

alias ini=$THISDIR/utils/init.sh
alias com=$THISDIR/utils/compile.sh
alias tst=$THISDIR/utils/test.sh
alias cln=$THISDIR/utils/clean.sh
alias sav=$THISDIR/utils/save.sh
