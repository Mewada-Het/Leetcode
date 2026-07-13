class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> row;
        
        string first = "qwertyuiop";
        string second = "asdfghjkl";
        string third = "zxcvbnm";

        for(char c : first)
            row[c] = 1;

        for(char c : second)
            row[c] = 2;

        for(char c : third)
            row[c] = 3;

        vector<string> result;

        for(string word : words){
            int keyboardRow = row[tolower(word[0])];
            bool valid = true;

            for(char c : word) {
                if(row[tolower(c)] != keyboardRow) {
                    valid = false;
                    break;
                }
            }

            if(valid){
                result.push_back(word);
            }
        }
        return result;
    }
};