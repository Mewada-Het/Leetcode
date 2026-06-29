class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int pt1 = m - 1;
        int pt2 = n - 1;
        int write = m + n - 1;
        while (pt2 >= 0)
        {
            if (pt1 >= 0 && nums1[pt1] > nums2[pt2])
            {
                nums1[write--] = nums1[pt1--];
            }
            else
            {
                nums1[write--] = nums2[pt2--];
            }
        }
    }
};