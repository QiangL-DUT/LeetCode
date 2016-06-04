class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1,0);
        int cur=1;
        int k=0;
        for(int i=1;i<=num;++i){
            v[i]=v[i-cur]+1; 
            ++k;
            if(cur==k){
                cur=cur<<1;
                k=0;
            }
        }
        return v;
    }
};
