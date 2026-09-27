class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCount = 0;
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'A' && word[i] <= 'Z') capCount++;
        }

        return capCount == word.size() || capCount == 0 || (capCount == 1 && word[0] >= 65 && word[0] <= 90 );
    }
};