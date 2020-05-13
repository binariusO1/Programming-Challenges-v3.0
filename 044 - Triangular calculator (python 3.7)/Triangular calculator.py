# programming challenge
# Triangular calculator (drawing version)
# python 3.7
# binariusO1

import turtle
from turtle import *

sc = turtle.Screen()
sc.setup(width=800, height=600)
sc.bgcolor("black")
sc.delay(0)
sc.tracer(0, 0)

triangles = []

def triangle_write(n):
    sum = 0
    for i in range(int(n)):
        triangles.append(int(int(n)+1))
    return 0

def draw_triangle(n):
    pen(shown=False, fillcolor='white', pencolor='white', pensize=2)
    penup()
    k = float(n)*7
    sety(k)
    y=0
    x=0
    for i in range(int(n)):
        k-=14
        x-=7
        sety(k)
        setx(x)
        j=i+1
        pendown()
        for i in range(j):
            begin_fill()
            pendown()
            forward(10)
            left(120)
            forward(10)
            left(120)
            forward(10)
            penup()
            end_fill()
            left(120)
            forward(14)
            sc.update()
    return 0

while True:
    n = input("Give a number: ")
    Tn = int(n) * (int(n) + 1) /2
    print("Triangular number: ",  int(Tn) )
    sc.reset()
    draw_triangle(n)

done()
