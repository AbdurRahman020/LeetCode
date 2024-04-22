#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, const std::vector<std::string>& wordList) {
        std::unordered_set<std::string> word_list(wordList.begin(), wordList.end());
        
        if (word_list.find(endWord) == word_list.end()) {
            return 0;
        }

        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1});
        int n = beginWord.length();

        while (!q.empty()) {
            std::string word = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 0; i < n; i++) {
                std::string left = word.substr(0, i);
                std::string right = word.substr(i + 1);
                for (char c = 'a'; c <= 'z'; c++) {
                    std::string new_word = left + c + right;
                    if (new_word == endWord) {
                        return step + 1;
                    }
                    if (word_list.find(new_word) != word_list.end()) {
                        q.push({new_word, step + 1});
                        word_list.erase(new_word);
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    std::cout << s.ladderLength("hit", "cog", {"hot","dot","dog","lot","log","cog"}) << std::endl;
    std::cout << s.ladderLength("hit", "cog", {"hot","dot","dog","lot","log"}) << std::endl;
    return 0;
}