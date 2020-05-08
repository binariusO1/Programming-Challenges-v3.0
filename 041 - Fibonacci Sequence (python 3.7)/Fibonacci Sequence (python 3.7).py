# programming challenge
# Fibonacci Sequence
# binariusO1

from turtle import *    #for drawing
#Fibonacci sequence
def Fibonacci(n):
    # First Fibonacci number is 0
    if n==1:
        return 0
    # Second Fibonacci number is 1
    elif n==2:
        return 1
    else:
        return Fibonacci(n-1)+Fibonacci(n-2)

#list of colors
list=[
'yellow','red','green',
'orange','cyan','purple',
'yellow','red','green',
'orange','cyan','purple',
'yellow','red','green',
'orange','cyan','purple',]

#first steps
seq=2
position()
right(180)
forward(10)
right(270)

#increase if you want resize graph
multiple = 4
while True:
    a = multiple*int(Fibonacci(seq))
    pen(fillcolor=list[int(seq)], pencolor='blue', pensize=2)
    begin_fill()
    circle(a,  90)
    left(90)
    forward(a)
    if(seq>2):
        left(90)
        forward(a)
        left(90)
        circle(a, 90)
    else:
        right(180)
        forward(a)
        left(90)
    end_fill()
    if seq > 15:
        break
    seq+=1

done()
