class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        // vector<int> prefix(n, 1);
        // vector<int> suffix(n, 1);

        //prefix
        for(int i = 0; i < n; i++){
            if(i == 0)
                ans[i] = 1;
            else
                ans[i] = ans[i-1] * nums[i-1];
        }

        int suffix = 1;
        //suffix
        for(int j=n-2; j>=0; j--){
            suffix *= nums[j+1];
            // suffix[j]=suffix[j+1] * nums[j+1];
            ans[j] *= suffix;
        }
        
        return ans;
    }
};