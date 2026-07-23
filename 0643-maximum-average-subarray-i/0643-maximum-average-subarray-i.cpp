class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long currSum = 0;
        
        for(int i = 0 ; i < k ; i++){
            currSum += nums[i]; 
        }

        long long maxSum = currSum;

        for (int i = k; i < nums.size(); i++) {
            currSum = currSum - nums[i - k] + nums[i];
            maxSum = max(maxSum, currSum);
        }

        return (double)maxSum/k;
    }
};