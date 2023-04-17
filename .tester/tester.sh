#!/bin/sh
pid="$(ps -ax | grep "./server" | head -n 1 | awk '{ print $1 }')"
loops=15
rm client
rm server
gcc -Wall -Wextra -Werror server.c -o server 
gcc -Wall -Wextra -Werror client.c -o client 

echo "Compilation and preparation done..."
echo "Starting the tests.."
echo "\n"
./.tester/_.sh $loops &
echo "the tester is running"
clear
echo "THE PID OR THE SERVER :::::::: "
./server
