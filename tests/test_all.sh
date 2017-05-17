#!/bin/bash

for i in *
do
    if [ -d $i ] && [ ../build/$i -nt $i/passed ] ; then
        echo "Testing $i...";
        touch $i/passed;
        for t in $i/*.in
        do
            echo "Running test $t";
            output=$(../build/$i < $t);
            expectedfile="$(echo "$t" | cut -d'.' -f 1 -).out"
            expected=$(cat $expectedfile);

            if [ ! "$output" == "$expected" ] ; then
                echo "Test $t failed";
                test -f $i/passed && rm $i/passed;
            fi
            echo "$output" | diff $expectedfile - ;
        done
    fi
done
