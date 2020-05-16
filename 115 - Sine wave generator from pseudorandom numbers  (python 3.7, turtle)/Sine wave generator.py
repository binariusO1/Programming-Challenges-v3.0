# programming challenge
# Sine wave generator from pseudorandom numbers (drawing version)
# python 3.7
# binariusO1

import math
import turtle
import random

screen = turtle.Screen()
screen.setup(width=1000, height=500)

sin = turtle.Turtle()
sin.penup()
sin.setpos(500,0)
sin.pendown()
sin.setpos(-500,0)
sin.speed(0)
w = 360*6
k = 50
s = 0
f = 0
kat = random.randint(45, 180)

for angle in range(w):
    y = (math.sin(math.radians(angle))+math.sin(math.radians(angle*(f+1)))/(f+1))
    sin.setpos(-500+(angle/2), y*float(k))
    k += float(s*0.1*(f/2))
    if angle%180 == 0:
        s = random.randint(-1,1)
        f = random.randint(0, 10)
screen.bye()
