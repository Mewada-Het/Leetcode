class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        map<int, int> freq;
        map<int, int> first;
        map<int, int> last;

        for (int i = 0; i < nums.size(); i++) {

            freq[nums[i]]++;
            if (first.find(nums[i]) == first.end()) {
                first[nums[i]] = i;
            }
            last[nums[i]] = i;
        }

        int maxFreq = 0;
        for (auto x : freq) {
            maxFreq = max(maxFreq, x.second);
        }

        int answer = nums.size();
        for (auto x : freq) {
            if (x.second == maxFreq) {

                int length = last[x.first] - first[x.first] + 1;

                answer = min(answer, length);
            }
        }
        return answer;
    }
};