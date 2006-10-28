#!/bin/sh 

SYS_TYPE=`head -n 1 conf-systype`
if [ $? -ne 0 ]
then
  echo "fatal: could not read conf-systype" 1>&2
  exit 1
fi

SLIB_DIR=`head -n 1 conf-slibdir`
if [ $? -ne 0 ]
then
  echo "fatal: could not read conf-slibdir" 1>&2
  exit 1
fi

RANLIB="ranlib"
if [ -f conf-ranlib ]
then
  RANLIB=`head -n 1 conf-ranlib`
  if [ $? -ne 0 ]
  then
    echo "fatal: could not read conf-ranlib" 1>&2
    exit 1
  fi
fi

case "${SYS_TYPE}"
in
  darwin)
    # darwin static archive bug
    for f in `ls ${SLIB_DIR}/*.a`
    do
      echo ${RANLIB} $f
      ${RANLIB} $f
    done
    ;;
  *)
    ;;
esac
