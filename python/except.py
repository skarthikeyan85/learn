# Handle all the exceptions!
#Setup
actor = {"name": "John Cleese", "rank": "awesome"}

#Function to modify, should return the last name of the actor - think back to previous lessons for how to get it
def get_last_name():
    try:
        return actor["last_name"]
    except:
        return ""

#Test code
get_last_name()
print("All exceptions caught! Good job!")
print("The actor's last name is %s" % get_last_name())

numbers = [34.6, -203.4, 44.9, 68.3, -12.2, 44.6, 12.7]
newlist = [word for word in numbers if word > 0.0]
print(numbers)
print(newlist)

import random

def lottery():
    # returns 6 numbers between 1 and 40
    for i in range(6):
        yield random.randint(1, 40)

    # returns a 7th number between 1 and 15
    yield random.randint(1,15)

rands = lottery()
#for random_number in lottery():
for random_number in rands:
    print("And the next number is... %d!" %(random_number))

def foo(first, second, third, *therest):
    print("First: %s" %(first))
    print("Second: %s" %(second))
    print("Third: %s" %(third))
    print("And all the rest... %s" %(list(therest)))

foo(1,2,3,4,5)
