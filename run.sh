#!/bin/sh

cat sky.txt        | kkmeans 2 | ./draw.py
cat kkmeans_ex.txt | kkmeans 3 | ./draw.py
