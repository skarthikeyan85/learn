import re
import operator

def word_count_engine(document):
  document = document.lower()
  document = re.sub(r'([^\s\w]|_)+', '', document)
  #print document
  word_list = document.split()

  word_map={}
  max_length = 0
  for idx,word in enumerate(word_list):
    if word in word_map:
      word_map[word][0] += 1
      if word_map[word][0] > max_length:
        max_length = word_map[word][0]
    else:
      word_map[word] = [1, idx]

  count_list = []
  for i in range(max_length+1):
    count_list.append([])
    
  ret = []
  for word in word_map.keys():
    count = word_map[word][0]
    count_list[count].append((word, word_map[word][1]))
    
  for i in range(max_length, 0, -1):
    c = count_list[i]
    c.sort(key = lambda x: x[1])
    for elem in c:
      ret.append([elem[0],str(i)])
  
  return ret
