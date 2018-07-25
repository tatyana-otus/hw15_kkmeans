#!/usr/bin/python

import sys
import matplotlib.pyplot as plt
import fileinput

color = {'cluster0\n':'ro','cluster1\n':'go','cluster2\n':'bo','cluster3\n':'co','cluster4\n':'mo','cluster5\n':'yo','cluster6\n':'ko'}

for line in fileinput.input():
    if line != '\n':
        data = line.split(";")
        plt.plot(data[0], data[1], color.get(data[2], 'wo'))
plt.show()
