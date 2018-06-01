class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        counts = collections.Counter(s)

        for e in t:
            if e in counts and counts[e] > 0:
                counts[e] -= 1
            else:
                return False
        
        for key, val in counts.items():
            if val:
                return False
        
        return True
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        counts={}
        for c in s:
            if (not c in counts):
                counts[c] = 1
            else:
                counts[c] += 1

        #counts = collections.Counter(s)

        for idx,c in enumerate(s):
            if counts[c] == 1:
                return idx

        return -1
