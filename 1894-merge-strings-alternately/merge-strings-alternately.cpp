class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word;
        int i = 0, j = 0;

        while (i < word1.length() && j < word2.length()) {
            word += word1[i];
            word += word2[j];
            i++;
            j++;
        }

        while (i < word1.length()) {
            word += word1[i];
            i++;
        }

        while (j < word2.length()) {
            word += word2[j];
            j++;
        }

        return word;
    }
};