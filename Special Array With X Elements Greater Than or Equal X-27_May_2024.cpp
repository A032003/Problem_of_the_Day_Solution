class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        
       
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= n; ++i) {
            int count = 0;
          
            for (int j = 0; j < n; ++j) {
                if (nums[j] >= i) {
                    count = n - j;  
                    break;
                }
            }
            if (count == i) {
                index = i;
                break; 
            }
        }
        return index;
    }
};

