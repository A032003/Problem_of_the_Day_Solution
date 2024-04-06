class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int cnt=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;

            }else if(s[i]==')'){
                if(cnt==0){
                    s[i]='#';
                }else{
                    cnt--;

                }
            }
        }
        cnt=0;

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')'){
                cnt++;

            }else if(s[i]=='('){
                if(cnt==0){
                    s[i]='#';
                }else{
                    cnt--;

                }
            }
        }
        cnt=0;

        for(int i=0;i<s.size();i++){
            if(s[i]!='#'){
                ans.push_back(s[i]);
            }
        }

        return ans;


    }
};
