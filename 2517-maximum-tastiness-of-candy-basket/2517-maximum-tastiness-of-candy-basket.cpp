class Solution {
public:
    void binarySearch(int l, int h, vector<int> price, int n, int k, int *ans){
        if(l<=h){
            int mid = (l+h)/2, i, j, count=1, last=0;
            for(int i =1; i <n; i++){
                if(price[i]-price[last]>=mid){
                    last=i;
                    count++;
                }
            }
            if(count>=k){
                (*ans) = mid;
                binarySearch(mid+1, h, price, n, k, ans);
            }
            else{
                binarySearch(l, mid-1, price, n, k, ans);
            }
        }
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n, ans = 0 , i , j;
        n = price.size();

        sort(price.begin(), price.end());
        binarySearch(0, price[n - 1] - price[0], price, n, k, &ans);

        return ans;
    }
};