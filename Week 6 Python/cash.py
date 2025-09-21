from cs50 import get_float

change=0
coins=0
while change<=0:
     change=get_float("Change: ")

def reduce(value):
    global change
    global coins
    while(change>=value):
        change=round(change-value,10)
        coins+=1

reduce(0.25)
reduce(0.10)
reduce(0.05)
reduce(0.01)

print(coins)

