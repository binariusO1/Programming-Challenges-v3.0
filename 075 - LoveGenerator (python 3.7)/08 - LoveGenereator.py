
from os import system, name
from time import sleep
import random

# define our clear function
def clear():
    # for windows
    if name == 'nt':
        _ = system('cls')

def loop():
    name1 = ""
    name2 = ""
    while (len(name1)==0 or len(name2)==0):
        name1 = input("Please, give me your name: ")
        name2 = input("Please, give me your's partner name: ")
        if(len(name1)==0 or len(name2)==0):
            print("Please, give both names")

    chance = random.randrange(abs(ord(name1[0])-ord(name2[0])), 100)
    sum = 0
    while (True):
        print("Your Love Percentage Result Revealed: ")

        print(sum , "%")

        if sum == chance:
            if chance > 80:
                print("Great Love!")
            elif chance <= 80 and chance > 60:
                print("Strong Love!")
            elif chance <= 60 and chance > 40:
                print("Just Love")
            elif chance <= 40 and chance > 20:
                print("Yeah, Love...")
            else:
                print("Is it Love?")

        sleep(0.04)
        if sum < chance:
            sum=sum+1
        if sum > chance/3:
            sleep(0.05)
        if sum > chance / 2:
            sleep(0.05)

        clear()
loop()