class Solution(object):
    def mergeAlternately(self, word1:str, word2:str) -> str:
        s = []
        w1, w2 = len(word1), len(word2)
        i, j = 0, 0
        while i < w1 and j < w2:
            s.append(word1[i])
            s.append(word2[j])
            i += 1
            j += 1
        if i < w1:
            s.append(word1[slice(i,w1)])
        if j < w2:
            s.append(word2[slice(i,w2)])
        return ''.join(s)

if __name__ == '__main__':
    s = Solution()
    print(s.mergeAlternately('abc', 'pqr'))
    print(s.mergeAlternately('abcd', 'pq'))
    print(s.mergeAlternately('ab', 'pqrs'))