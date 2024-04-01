class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int list=s.length()-1;
        while(list>=0 && s[list]==' '){
            list--;
        }
         while(list>=0 && s[list]!=' '){
            len++;
            list--;
           
        }
        return len;
    }
};
