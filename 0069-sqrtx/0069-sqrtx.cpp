class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        int lp = 1;
        int rp = x/2;
        int ans = 1;
        
        while(lp <= rp ){
            int mid = lp + (rp-lp)/2;
            if(mid == x/mid){
                return mid;
            }else if(mid > x/mid){
                rp = mid - 1;
            }else{
                ans = mid;
                lp = mid + 1;
            }
        }
        return ans;
    }
};