//Dynamic Programming O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int num=nums.size();
        vector<int> v(num,0);
        for(int i=0;i<num;++i){
            int cur=1;
            for(int j=i-1;j>=0;--j){
                if((nums[i]>nums[j])&&(cur<v[j]+1))
                    cur=v[j]+1;
            }
            v[i]=cur;
        }
        int maxLen=0;
        for(int i=0;i<num;++i){
            if (maxLen<v[i])
                maxLen=v[i];
        }
        return maxLen;
    }
};
