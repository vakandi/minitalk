#!/bin/sh
cp client client2
cp client client3

pid="$(ps -ax | grep "./server" | head -n 1 | awk '{ print $1 }')"
emoji="🕵️"
cp client client2
cp client client3

./client $pid " \
	"
./client $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client2 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client3 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &


./client $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client2 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client3 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &

./client $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client2 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client3 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &

./client $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client2 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client3 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &

./client $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client2 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client3 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &

./client $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client2 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client3 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &


./client $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client2 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &
./client3 $pid "test $RANDOM sedhse    random : $RANDOM    $emoji" &



