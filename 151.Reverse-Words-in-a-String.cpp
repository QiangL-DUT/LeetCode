class Solution {
public:
    void reverseWords(string &s) {
        int n=s.size();
        int cur=0;
        int i=0;
        while ((i<n)&&(s[i]==' '))    //Get rid of spaces in front of the string
            i++;
        bool space=false;
        for (;i<n;++i){               //Get rid of the extra spaces between two words
            if(s[i]==' ')
                space=true;
            else if (space){
                s[cur++]=' ';
                s[cur++]=s[i];
                space=false;
            }
            else{
                s[cur++]=s[i];
            }
        }
        s.erase(cur,n-cur);           
        int begin=0;
        for (i=0;i<cur;++i){         //Through two flips.
            if (s[i]==' '){
                flipStr(s,begin,i-1);
                begin=i+1;
            }
        }
        flipStr(s,begin,cur-1);
        flipStr(s,0,cur-1);
    }
private:
    void flipStr (string &s,int begin,int end){
        char c;
        for (int i=begin,j=end;i<j;++i,--j){
            c=s[i];
            s[i]=s[j];
            s[j]=c;
        }
    }
};
