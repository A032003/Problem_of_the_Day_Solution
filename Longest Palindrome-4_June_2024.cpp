class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;

        for(char ch:s){
            mp[ch]++;
        }
        int len=0;
        bool oddchar=false;

        for(auto it:mp){
            if(it.second%2==0){
                len=len+it.second;

            }else{
                len=len+(it.second-1);
                oddchar=true;
            }
        }

        if(oddchar)
        return len+1;
        return len;
    }
};
