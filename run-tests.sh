#!/bin/sh

[ -n "$1" ] && variant="$1" || variant=quick
cs=$(./test-aes | md5sum | cut -d' ' -f1)
test "$cs" = "a650115e1a87a51cc9f8f1f58cbbdd99" \
  || { echo "test-aes: failed">&2; exit 1; }
./test-constanttime \
  || { echo "test-constanttime: failed">&2; exit 1; }
case $variant in
  quick|10x) lines=10010; sum=ad3314ecd86351da7a20244097a08de6 ;;
  1000x) lines=123456; sum=707212358360ae459bc0ef293a5354e8 ;;
  10000x) lines=1234567; sum=3b2bc877e4e64efbfe39945ac102c768 ;;
  100000x) lines=12345678; sum=ef3831c8b2087ebf6844f2265e1da2c2 ;;
  1000000x) lines=123456789; sum=5e29ea7450475dc419a0f95afde0cfdc ;;
  full|10000000x) lines=1001000000; sum=3ceb64843c00984c5c2b7897f499141b ;;
esac
cs=$(./test-poly1305aes | head -n$lines | md5sum | cut -d' ' -f1)
test "$cs" = "$sum" \
  || { echo "test-poly1305aes: failed">&2; exit 1; }

