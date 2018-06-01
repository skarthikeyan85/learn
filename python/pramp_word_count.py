import re
import operator
from collections import Counter

def word_count_engine(document):
  document = document.lower()
  document = re.sub(r'([^\s\w]|_)+', '', document)
  #print document
  l = document.split()
  m = Counter(l)
  
  sorted_m = sorted(m.items(), key=operator.itemgetter(1))
  #sorted_m = reversed(sorted_m)
  ret = []
  for w in sorted(m, key=m.get, reverse=True):
    l = []
    l.append(w)
    l.append(str(m[w]))
    ret.append(l)
  
  #for i in reversed(sorted_m):
    
  #print sorted_m
  #for key, value in m.iteritems():
  #  ret.append([key, str(value)])
  return ret
