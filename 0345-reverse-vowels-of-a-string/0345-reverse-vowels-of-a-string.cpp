class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' ||
               c == 'i' || c == 'I' || c == 'o' || c == 'O' ||
               c == 'u' || c == 'U';
    }

    string reverseVowels(string s) {
        int lptr = 0;
        int rptr = s.size() - 1;

        while (lptr < rptr) {

            while (lptr < rptr && !isVowel(s[lptr])) {
                lptr++;
            }

            while (lptr < rptr && !isVowel(s[rptr])) {
                rptr--;
            }

            if (lptr < rptr) {
                swap(s[lptr], s[rptr]);
                lptr++;
                rptr--;
            }
        }
        return s;
    }
};