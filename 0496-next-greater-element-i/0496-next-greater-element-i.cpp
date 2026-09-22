class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> nextGreater;

        for (int i = 0; i < nums2.size(); i++) {

            nextGreater[nums2[i]] = -1;
            for (int j = i + 1; j < nums2.size(); j++) {

                if (nums2[j] > nums2[i]) {
                    nextGreater[nums2[i]] = nums2[j];
                    break;
                }
            }
        }
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            result.push_back(nextGreater[nums1[i]]);
        }

        return result;
    }
};