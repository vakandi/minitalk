#!/bin/sh
sleep 3s
pid="$(ps -ax | grep "./server" | head -n 1 | awk '{ print $1 }')"
emoji="🕵️"
loop=15
var=1
./client $pid " \
	"

while [ $var -le $loop ]
do
	./client $pid " Test random number ::::: $RANDOM Test emoji:: $emoji"
	./client $pid " Test random number ::::: $RANDOM Test emoji:: $emoji"
	./client $pid " Test random number ::::: $RANDOM Test emoji:: $emoji"
	./client $pid "                                                     "
	./client $pid " ::::::::::::      Loops $var done  ::::::  :::::: "
	./client $pid "_________________________________________________"
	var=$((var+1))
done
rm nohup.out
