class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> freq;

        // Frequency required from t
        for (char ch : t) {
            freq[ch]++;
        }

        int targetRemain = t.length();

        int start = 0;
        int minStart = 0;
        int minLen = INT_MAX;

        for (int end = 0; end < s.length(); end++) {

            // Include s[end] in the window
            char ch = s[end];

            if (freq.find(ch) != freq.end()) {
                if (freq[ch] > 0) {
                    targetRemain--;
                }

                freq[ch]--;
            }

            // Window is valid
            while (targetRemain == 0) {

                // Update answer
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }

                // Remove s[start]
                char leftChar = s[start];

                if (freq.find(leftChar) != freq.end()) {
                    freq[leftChar]++;

                    // We just removed a required character
                    if (freq[leftChar] > 0) {
                        targetRemain++;
                    }
                }

                start++;
            }
        }

        if (minLen == INT_MAX) return "";

        return s.substr(minStart, minLen);
    }
};