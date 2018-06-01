#pass # your code goes here

'''
build a map for the arr
eliminate chars from the str and decrement the str map
such that i can still be valid with the arr map
'''

def get_shortest_unique_substring(arr, str):
  arr_counts={}
  for elem in arr:
    arr_counts[elem] = 0

  ans = ''
  uc = 0
  h = 0
  i = 0
  
  while i < len(str):
    if str[i] not in arr_counts:
      i += 1
      continue
    
    tc = arr_counts[str[i]]
    if (tc == 0):
      uc += 1
    arr_counts[str[i]] = tc + 1
    
    while (uc == len(arr)):
      temp_len = i - h + 1
      if ans == "" or temp_len < len(ans):
        ans = str[h:i+1]
      
      if (str[h] in arr_counts):
        hc = arr_counts[str[h]] - 1
        if (hc == 0):
          uc -= 1
        arr_counts[str[h]] = hc
      
      h += 1
    
    i += 1
  
  return ans

'''
def all_present(arr_counts, string):
  #if string == "zyx":
  #  print "here"
  for key in arr_counts:
    if key not in string:
      return False
  return True

def get_shortest_unique_substring(arr, input_string):
  length = len(input_string)
  ans = ''
  two=''.join(arr)
  arr_counts = collections.Counter(two)
  for i in xrange(length):
    for j in xrange(i,length):
      curr = (input_string[i:j + 1])
      if all_present(arr_counts, curr):
        if ans is '' or len(curr) < len(ans):
          ans = curr
  return ans
'''

print get_shortest_unique_substring(['x','y','z'], 'xyyzyzyx') 
