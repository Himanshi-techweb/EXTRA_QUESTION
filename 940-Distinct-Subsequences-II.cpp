class Solution {
public:
    // unordered_set<string> st;
    vector<long long> dp;
    const int MOD =1e9 + 7;
    long long solve(int i,string &str){
        if(i>=str.size())return 0;
        long long count=0;
        if(dp[i]!=-1)return dp[i];
        vector<int> visit(26,0);
        for(int j=i;j<str.size();j++){
            if(!visit[str[j]-'a']){
                visit[str[j]-'a']=1;
                count=(count+(1+solve(j+1,str))%MOD)%MOD;
            }
        }
        return dp[i]=count%MOD;
    }
    int distinctSubseqII(string s) {
        string str="";
        dp.resize(s.size(),-1);
        return solve(0,s);
        
    }
};