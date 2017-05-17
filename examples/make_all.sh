#!/bin/sh

for i in *.cpp
do
    if [ ../src/$i -nt ../build/$(echo "$i" | cut -d'.' -f 1 -) ] || [ ! -f ../build/$(echo "$i" | cut -d'.' -f 1 -) ]; then
        echo "Compiling $i..."
        c++ -pedantic -Wall -Wextra -Werror -O3 -std=c++14 -I../src -o ../build/$(echo "$i" | cut -d'.' -f 1 -) $i || exit 1
    fi
done

