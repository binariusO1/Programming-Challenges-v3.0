# programming challenge
# FizzBuzz
# python 3.7
# binariusO1
# 
a=0
while a<100:
    i=int(input())
    s=""
    t=""
    if i%5==0:
        s="FIZZ"
    if i%3==0:
        t="BUZZ"
    if i%3 and i%5:
        print(i,end='')
    print(s+t)
