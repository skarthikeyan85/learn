def flatten_dictionary(dictionary):
    #pass # your code goes here
    #ret={}
    #for k,v in dictionary:
    #type(v)
    #if it is also a dictionary:
      #recursivel call dic=flattern_dictionary
      #append keys and set key = value
    #else
      #key = value in the return dictionary
      
    ret={}
    #list instead of dictionary - for collecting return
    for k,v in dictionary.items():
      if isinstance(v, dict):
        # set this to a variable
        # and iterate over the new dictionary variable
        for nk, nv in flatten_dictionary(v).items():
          ret[append_key(k, nk)] = v
          # the append key can come in handy here
      else:
        ret[k] = v;
    return ret

def append_key(right_key, left_key):
   if right_key and left_key:
      return right_key + '.' + left_key
   elif right_key:
      return right_key
   elif left_key:
      return left_key
   
