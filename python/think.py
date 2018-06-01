def sumall(*args):
    ans = 0
    for i in args:
        ans += i
    return ans

fruit = 'banana'
letter = fruit[1]
print letter
letter = fruit[::-1]
print letter
for char in fruit:
    print char
print 'an' in 'banana'
print sumall(1,2,3,4) 
print zip('Anne', 'Elk') 
print zip([1,3,4], [5,5,6,6])
camels = 42
cstr = 'I have spotted %d camels.' % camels
print cstr
import os
print os.getcwd()
