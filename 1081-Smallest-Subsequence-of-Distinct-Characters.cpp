class Solution {
public:

    string smallestSubsequence(string s) {
        stack<int> st;
        vector<int> index(26,-1);
        vector<bool> visit(26,false);
        string str="";
        for(int i=s.size()-1;i>=0;i--){
            if(index[s[i]-'a']==-1)index[s[i]-'a']=i;
        }
        for(int i=0;i<s.size();i++){
            if(visit[s[i]-'a'])continue;
            while(str.size()>0 && str.back()-'a'>s[i]-'a'){
                if(index[str.back()-'a']>i){
                    visit[str.back()-'a']=false;
                    str.pop_back();

                }
                else break;
            }
            str+=s[i];
            visit[s[i]-'a']=true;
        }
        return str;
        
    }
};