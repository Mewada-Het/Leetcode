class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int lp = 0, rp = n- 1;

        while(lp <= rp){
            int mid = lp + (rp-lp)/2;

            //edge cases
            if(mid == 0 && nums[0] != nums[1]) return nums[0];
            if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[n-1];

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

            if(mid % 2 == 0){                 //even
                if(nums[mid] == nums[mid-1]){   //left
                    rp = mid - 1;
                }else{                          //right
                    lp = mid + 1;
                }
            }else{                            //odd
                if(nums[mid] == nums[mid-1]){   //right
                    lp = mid + 1;
                }else{                          //left
                    rp = mid - 1;
                }
            }
        }
        return -1;
    }
};