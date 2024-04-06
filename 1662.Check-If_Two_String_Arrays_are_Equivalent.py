class Solution(object):
    def arrayStringsAreEqual(self, word1: list[str], word2: list[str]) -> bool:
        w1,w2 = ''.join(word1), ''.join(word2)
        return w1 == w2

if __name__ == '__main__':
    s = Solution()
    print(s.arrayStringsAreEqual(["ab", "c"], ["a", "bc"]))
    print(s.arrayStringsAreEqual(["a", "cb"], ["ab", "c"]))
    print(s.arrayStringsAreEqual(["abc", "d", "defg"], ["abcddefg"]))