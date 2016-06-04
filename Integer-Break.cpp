//Dynamic Programming
class Solution {
public:
    int integerBreak(int n) {
        vector<int> v(n-1,0);
        for(int i=0;i<n-1;++i){
            int cur=i+1;
            for(int j=0;j<i;++j){
                int product=v[j]*v[i-j-1];
                if(product>cur)
                    cur=product;
            }
            v[i]=cur;
        }
        int maxPro=0;
        for(int i=1;i<n;++i){
            int product=v[i-1]*v[n-i-1];
            if(product>maxPro)
                maxPro=product;
        }
        return maxPro;
    }
};
