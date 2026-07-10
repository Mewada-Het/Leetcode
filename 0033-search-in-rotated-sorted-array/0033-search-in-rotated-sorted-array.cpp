class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) return mid;

            bool leftSorted = nums[st] <= nums[mid];

            if (leftSorted) {
                bool targetInLeft = nums[st] <= target && target < nums[mid];
                if (targetInLeft) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                bool targetInRight = nums[mid] < target && target <= nums[end];
                if (targetInRight) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};