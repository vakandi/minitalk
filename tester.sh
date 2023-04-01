#!/bin/sh
pid="$(ps -ax | grep "./server" | head -n 1 | awk '{ print $1 }')"
emoji="🕵️"

rm client
rm server
gcc -Wall -Wextra -Werror server.c -o server 
gcc -Wall -Wextra -Werror client.c -o client 

echo "Compilation and preparation done..."
echo "Starting the tests.."
echo "\n"
./_.sh &
echo "the tester is running"
clear
echo "THE PID OR THE SERVER :::::::: "
./server
