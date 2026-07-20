class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0 ; i < flowerbed.size() ; i++){
            if(n == 0) return true;
            bool left = (i == 0) || (flowerbed[i-1] == 0);
            bool right = (i == flowerbed.size() - 1) || (flowerbed[i+1] == 0);

            if(!flowerbed[i] && left && right){
                flowerbed[i] = 1;
                n--;
            }

            if(n == 0) return true;
        }
        return false;
    }
};