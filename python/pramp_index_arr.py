# karthik
# and u are ?
'''
Oleg
arr = [-8,0,2,5]
.,.,.,2
'''

def index_equals_value_search(arr):
  # for every element: 
  #   check if index == value
  #     return index
  # return -1
  #your code goes here
  # o(n)
  
  #for idx,elem in enumerate(arr):
  #  if (elem == idx):
  #    return idx
  # since it is a sorted array - I am thinking how to use binar search kind of operation to get this #
  # but then not sure how to terminate 
  # since the lowest index is required ...
  # so thinking ...
  l = 0
  r = len(arr)-1
  ret = -1
  while (l <= r):
    mid = l + (r - l)/2
    val = arr[mid] - mid
    if (val == 0):
      ret = mid
      r = mid - 1
    elif (val > 0):
      r = mid - 1
    elif (val < 0):
      l = mid + 1
  return ret

ret = index_equals_value_search([-8,0,2,5])
print ret
