# programming challenge
# Snake game
# Python 3.7
# binariusO1

# import only system from os
from os import system, name
# import sleep to show output for some time period
from time import sleep
import keyboard  # using module keyboard
import random    # for random
import sys       # for esc->exit

# define clear function
def clear():
    # for windows
    if name == 'nt':
        _ = system('cls')

# some variables
n = 44
m = 20
score =0
num =4  # down = 0, up = 3, right = 2, left = 1
dir = 0

class Snake:
    def __init__(self,x,y):
        self.x = 0
        self.y = 0

class Fruit:
    def __init__(self,x,y):
        self.x = 0
        self.y = 0

s=[]
f = Fruit(10, 10)

for i in range(100):
    #s[i]=Snake
    s.append(Snake(0,0))

s[0].x=int(n/2)
s[0].y=int(m/2)
s[1].x=int(n/2)
s[1].y=int(m/2-1)
s[2].x=int(n/2)
s[2].y=int(m/2-2)
s[3].x=int(n/2)
s[3].y=int(m/2-3)

def Tick():
    global num
    global f
    global score
    global dir
    defeat = 0                                   # comment '#' if you want board without braces
    for i in range(num-1,0,-1):
       s[i].x=s[i-1].x
       s[i].y=s[i-1].y
    if dir == 0:
        if s[0].y<m-1: s[0].y+=1
        # else: s[0].y=0                         # uncomment '#' if you want board without braces
        else: defeat = 1                         # comment '#' if you want board without braces
    if dir == 1:
        if s[0].x>0: s[0].x-=1
        # else: s[0].x=n-1                       # uncomment '#' if you want board without braces
        else: defeat = 1                         # comment '#' if you want board without braces
    if dir == 2:
        if s[0].x<n-1: s[0].x+=1
        # else: s[0].x=0                         # uncomment '#' if you want board without braces
        else: defeat = 1                         # comment '#' if you want board without braces
    if dir == 3:
        if s[0].y>0: s[0].y-=1
        # else:  s[0].y=m-1                      # uncomment '#' if you want board without braces
        else: defeat = 1                         # comment '#' if you want board without braces

    if s[0].x == f.x and s[0].y == f.y:
        num += 1
        s[num-1].x = s[num-2].x
        s[num - 1].y = s[num - 2].y
        f.x = random.randrange((0), n-1)
        f.y = random.randrange((0), m-1)
        score += 1
    for i in range(1,num-1,1):
        if s[0].x == s[i].x and s[0].y == s[i].y or defeat == 1: # delete phrase ('or defeat == 1') if you want board without braces
            num = 4
            s[0].x = int(n / 2)
            s[0].y = int(m / 2)
            s[1].x = int(n / 2)
            s[1].y = int(m / 2 - 1)
            s[2].x = int(n / 2)
            s[2].y = int(m / 2 - 2)
            s[3].x = int(n / 2)
            s[3].y = int(m / 2 - 3)
            f.x = random.randrange((0), n - 1)
            f.y = random.randrange((0), m - 1)
            dir = 0
            score = 0
            defeat = 0                      # uncomment '#' if you want board without braces

def loop():
    speed = float(0.05)
    global dir
    f.x = int(n / 2)
    f.y = int(m / 2)
    # put fruit away from snake
    while f.x == s[0].x or f.x == s[1].x or f.x == s[2].x or f.x == s[3].x:
        f.x = random.randrange((0), n - 1)
    while f.y == s[0].y or f.y == s[1].y or f.y == s[2].y or f.y == s[3].y:
        f.y = random.randrange((0), m - 1)
    while(True):

        # drawing score
        print("score: " , f"{score:04d}")
        # print("s0: " , s[0].x,s[0].y , "s1: " ,s[1].x,s[1].y , "s2: " ,s[2].x,s[2].y, "s3: " ,s[3].x,s[3].y , "dir: ", dir, "num: ", num, "f:",f.x,f.y)

        # create a table
        a = [[' '] * n for i in range(m)]


        # update Snake's body
        Tick()

        # drawing fruit
        a[f.y][f.x]="*"

        # drawing Snake's head
        a[s[0].y][s[0].x] = "@"

        # drawing Snake's tail
        for i in range(1,num-1,1):
            a[s[i].y][s[i].x]="x"

        a[s[num-1].y][s[num-1].x] = "+"

        # drawing table
        print('_'*(n+2))
        for x in a:
            print('|',*x,'|', sep ='')
        print('-' * (n + 2))

        # clear table
        a.clear()

        # make game some harder
        if score > 15:
            speed = 0.04
            if score > 45:
                speed = 0.03

        # hotkeys
        k=0
        while k != 4:
            sleep(speed)
            if keyboard.is_pressed('down') and dir != 3:
                dir = 0
            if keyboard.is_pressed('up') and dir != 0:
                dir = 3
            if keyboard.is_pressed('left') and dir != 2:
                dir = 1
            if keyboard.is_pressed('right') and dir != 1:
                dir = 2
            if keyboard.is_pressed('esc'):
                sys.exit("\nHave a nice day")
            k += 1

        #clear screen
        clear()

loop()




