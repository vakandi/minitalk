#!/bin/sh
pid="$(ps -ax | grep "./server" | head -n 1 | awk '{ print $1 }')"
emoji="🕵️"
cp client client2
cp client client3

./client $pid " \
	"

./client $pid "gsw$RANDOMsedhse    random : $RANDOM    $emoji"
./client2 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"
./client3 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"

./client $pid "gsw$RANDOMsedhse    random : $RANDOM    $emoji"
./client2 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"
./client3 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"

./client $pid "gsw$RANDOMsedhse    random : $RANDOM    $emoji"
./client2 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"
./client3 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"

./client $pid "gsw$RANDOMsedhse    random : $RANDOM    $emoji"
./client2 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"
./client3 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"

./client $pid "gsw$RANDOMsedhse    random : $RANDOM    $emoji"
./client2 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"
./client3 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"

./client $pid "gsw$RANDOMsedhse    random : $RANDOM    $emoji"
./client2 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"
./client3 $pid "gsw$RANDOMsedhse    random : $RANDOM   $emoji"

