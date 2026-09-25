class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freq[26] = {};

        for (char chr : magazine) {
            freq[chr - 'a']++;
        }

        for (char chr : ransomNote) {
            if (freq[chr - 'a'] > 0) {
                freq[chr - 'a']--;
            } else {
                return false;
            }
        }
        return true;
    }
};