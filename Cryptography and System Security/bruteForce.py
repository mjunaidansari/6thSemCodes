import random

targetPassword = input("Enter the password you wish to test: ")

def crack(targetPassword):
    status = True
    i = 0
    while status: 
        guess = ""
        i += 1
        for _ in range(len(targetPassword)): 
            guess += chr(random.randint(97, 122))
        if guess == targetPassword: 
            status = False
    return i

print("Password Cracked in ", crack(targetPassword), "iterations.")