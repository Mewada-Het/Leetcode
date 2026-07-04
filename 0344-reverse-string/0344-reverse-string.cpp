class Solution {
public:
    void reverseString(vector<char> &s)
    {
        int lp = 0, rp = s.size() - 1;
        while (lp < rp)
        {
            swap(s[lp++], s[rp--]);
        }
    }
};