# programming challenge
# 03 Calculate Age in Seconds
# python 3.7
# binariusO1
# based on my old project in C++
import sys

def menu():
    print("\tI have: ")
    print("[1] Celsius degree")
    print("[2] Farenheit degree")
    print("[3] Kelvin degree")
    print("[4] Rankine degree")
    print("[5] Reaumur degree")
    print("[6] Exit")
    pick = float(input("Enter a choice: "))
    if pick == 6:
        sys.exit("\nHave a nice day")
    return pick

def menu2():
    print("\n\tAnd i want to convert to: ")
    print("[1] to Celsius degree")
    print("[2] to Farenheit degree")
    print("[3] to Kelvin degree")
    print("[4] to Rankine degree")
    print("[5] to Reaumur degree")
    print("[6] Exit")
    pick = float(input("Enter a choice: "))
    if pick == 6:
        sys.exit("\nHave a nice day")
    return pick

def multiples(c1,c2):
    result = float(input("Enter a value: "))
    degree=["Celsius","Farenheit","Kelvin","Rankine","Reaumur" ]
    print("\n" + "The result is: \n")
    #Celsius to...
    if c1 == 1:
        if c2 == 1:
            result = result
        elif c2 == 2:
            result = result * (1.00 * 9 / 5) + 32
        elif c2 == 3:
            result = result + 273.15
        elif c2 == 4:
            result = (result + 273.15) * 1.00 * 9 / 5;
        else:
            result = result * 1.00 * 4 / 5;
        # Farenheit to...
    elif c1 == 2:
        if c2 == 1:
            result = (result - 32) * (1.00 * 5 / 9);
        elif c2 == 2:
            result = result
        elif c2 == 3:
            result = (result + 459.67) * (1.00 * 5 / 9);
        elif c2 == 4:
            result = (result + 459.63);
        else:
            result = (result - 32) * (1.00 * 4 / 9);
        # Kelvin to...
    elif c1 == 3:
        if c2==1:
            result = result - 273.15;
        elif c2 == 2:
            result = result * (1.00 * 9 / 5) + 32;
        elif c2 == 3:
            result = result
        elif c2 == 4:
            result = (result + 273.15) * 1.00 * 9 / 5;
        else:
            result = (result - 273.15) * (1.00 * 4 / 5);
        # Rankine to...
    elif c1 == 4:
        if c2 == 1:
            result = (result - 491.67) * (1.00 * 5 / 9);
        elif c2 == 2:
            result = result - 459.67;
        elif c2 == 3:
            result = result + 273.15;
        elif c2 == 4:
            result=result
        else:
            result = (result - 491.67) * 1.00 * 4 / 9;
        # Reaumur to...
    if c1 == 5:
        if c2 == 1:
            result = result * (1.00 * 5 / 4);
        elif c2 == 2:
            result = result * (1.00 * 9 / 4) + 32;
        elif c2 == 3:
            result = result * (1.00 * 5 / 4) + 273.15;
        elif c2 == 4:
            result = result * (1.00 * 9 / 4) + 491.67;
        else:
            result = result
    f_result = "{:.2f}".format(result)
    print(degree[int(c1-1)] + " is: " + f_result+" of " + degree[int(c2-1)] + " deegree")

def main():
    convert = 0
    convertTo = 0

    choice = menu()
    convert = choice
    while choice > 6:
            print("Invalid entry")
            choice = menu()

    choice2 = menu2()
    convertTo = choice2
    while choice2 > 6:
            print("Invalid entry")
            choice2 - menu2()

    multiples(convert,convertTo)

    print("\n")
    main()

main()

