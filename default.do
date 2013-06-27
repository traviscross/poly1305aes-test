# -*- mode:sh -*-
exec >&2; set -- $1 ${1%.*} $3
[ -n "$CC" ] || export CC=gcc
[ -n "$CFLAGS" ] || export CFLAGS="-g3 -Wall -O3 -fPIC"
[ -n "$CPPFLAGS" ] || export CPPFLAGS=""
[ -n "$LDFLAGS" ] || export LDFLAGS="-lssl -lgmp"

case $1 in
  all)
    redo-ifchange poly1305aes_test.a poly1305aes_test.so
    ;;
  clean) rm -f *.o *.d *.a *.so ;;
  distclean) redo clean; rm -rf .redo .do_built* *.did ;;
  poly1305aes_test.d)
    cat > $3 <<EOF
$3: aes_openssl.o \
constanttime_isequal.o \
poly1305aes_test_authenticate.o \
poly1305aes_test_clamp.o \
poly1305aes_test_verify.o \
poly1305_gmp.o
EOF
    ;;
  *.a)
    redo-ifchange $2.d; read DEPS < $2.d; DEPS=${DEPS#*:}
    redo-ifchange $DEPS
    ar cr $3 $DEPS
    ;;
  *.so)
    redo-ifchange $2.d; read DEPS < $2.d; DEPS=${DEPS#*:}
    redo-ifchange $DEPS
    $CC $LDFLAGS $DEPS -shared -o $3
    ;;
  *.o)
    redo-ifchange $2.c
    $CC -MD -MF $2.d $CPPFLAGS $CFLAGS -c -o $3 $2.c
    read DEPS < $2.d; DEPS=${DEPS#*:}
    redo-ifchange $DEPS
    ;;
esac