#!/bin/sh

for i in *.cpp
do
    rm ../build/$(echo "$i" | cut -d'.' -f 1 -)
done
