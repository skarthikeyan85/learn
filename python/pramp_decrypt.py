
def decrypt(word):
  if (not word):
    return word

  #convert string to number list
  ans = [ord(c) for c in word]
  second = ans
  
  #do the reverse of step3
  i = 1
  while (i < len(ans)):
    second[i] = ans[i] - ans[i-1]
    while (not(second[i] >= 97 and second[i] <= 123)):
      second[i] += 26
    second[i] += ans[i-1]
    i += 1
    
  #do the reverse of step2
  i = len(ans) - 1
  while (i >= 1):
    second[i] -= second[i-1]
    i -= 1
  second[i] -= 1
  cans = [chr(c) for c in second]
  return "".join(cans)

print (decrypt("dnotq"))
print (decrypt("flgxswdliefy"))
