class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;

        priority_queue<string> maxHeap;
        int n= word.length();
        int maxLen = n - numFriends + 1;

        for(int j = 0; j < n; j++) {
            int len = min(n - j, maxLen);
            maxHeap.push(word.substr(j, len));
        }

        return maxHeap.top();  // Lexicographically largest substring
    }
};
