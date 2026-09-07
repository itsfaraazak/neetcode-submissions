class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        std::unordered_map<char, int> freq;
        for (char c : s) {
            ++freq[c];
        }
        for (char c : t) {
            if (freq.contains(c)) {
                --freq[c];
            } else {
                return false;
            }
        }
        for (std::pair<char, int> charFreq : freq) {
            if (charFreq.second != 0) {
                return false;
            }
        }
        return true;

    }

};
