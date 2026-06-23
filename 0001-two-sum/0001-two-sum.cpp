class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> data;
        for (int i = 0; i < nums.size(); i++)
        {
            int required = target - nums[i];
            if (data.find(required) != data.end())
            {
                return {data[required], i};
            }
            else
            {
                data[nums[i]] = i;
            }
        }
        return {};
    }
};