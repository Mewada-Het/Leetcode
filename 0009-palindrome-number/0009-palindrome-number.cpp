class Solution {
public:
    bool isPalindrome(int x) {
        int originalValue = x;
        long long reversed = 0;
        if (x < 0)
            return false;
        while (x > 0)
        {
            int lastDigit = x % 10;
            x /= 10;
            reversed = reversed * 10 + lastDigit;
        }
        if (originalValue == reversed)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};