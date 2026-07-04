class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int p1 = 0;
        int p2 = 0;
        string result;
        result.reserve(word1.length() + word2.length());

        while (p1 < word1.length() || p2 < word2.length())
        {
            if (p1 < word1.length())
                result += word1[p1++];
            if (p2 < word2.length())
                result += word2[p2++];
        }
        return result;
    }
};