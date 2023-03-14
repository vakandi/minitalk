#!/bin/sh
pid="16433"
cp client client2
cp client client3

./client $pid " \
	"

./client $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"
./client2 $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"
./client3 $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"

./client $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"
./client2 $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"
./client3 $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"


./client $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"
./client2 $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"
./client3 $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"


./client $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"
./client2 $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"
./client3 $pid "gsw$RANDOMsedhse    random : $RANDOM    😀"

