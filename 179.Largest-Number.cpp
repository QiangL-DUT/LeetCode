class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> sNums(nums.size(),"");
        string str="";
        for(int i=0;i<nums.size();++i){
            sNums[i]=to_string(nums[i]);
        }
        sort(sNums.begin(),sNums.end(),compare);
        int i=0;
        while((i<nums.size())&&(sNums[i]=="0"))
            ++i;
        for(;i<nums.size();++i){
            str+=sNums[i];
        }
        if(str=="")
            return "0";
        return str;
    }
private:
    static bool compare(string& s1, string& s2){
        return ((s1+s2)>(s2+s1));
    }
};
