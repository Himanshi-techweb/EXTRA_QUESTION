1class Solution {
2public:
3    string result="";
4    bool issubsequence(string &s,string &curr,int k){
5        int i=0;int j=0;
6        while(j<k*curr.size() && i<s.size()){
7            if(s[i]==curr[j%curr.size()]){
8                j++;
9            }
10            i++;
11        }
12        return j==k*curr.size();
13    }
14    bool backtracking(string &s ,string &curr,vector<int> &temprequire,vector<bool> &canuse,int maxlen,int k){
15
16        // if(curr.size()>maxlen)return;
17        // if(curr.size()>result.size() || (curr.size()==result.size() && curr>result ) && issubsequence(s,curr,k)){
18        //     result=curr;
19        //     return;
20        // }
21        if(curr.size()==maxlen && issubsequence(s,curr,k)){
22            result=curr;
23            return true;
24        }
25
26        //
27        for(int i=25;i>=0;i--){
28            if(!canuse[i] || temprequire[i]==0)continue;
29            curr.push_back(i+'a');
30            temprequire[i]--;
31            if(backtracking(s,curr,temprequire,canuse,maxlen,k))return true;
32            curr.pop_back();
33            temprequire[i]++;
34
35        }
36        return false;
37    }
38    string longestSubsequenceRepeatedK(string s, int k) {
39        int n=s.size();
40        int maxlen=n/k;
41        vector<int> freq(26,0);
42        vector<int> require(26,0);
43        vector<bool> canuse(26,0);
44        for(int i=0;i<n;i++){
45           freq[s[i]-'a']++;
46        
47        }
48
49        //check if it can be use 
50        for(int i=0;i<26;i++){
51            if(freq[i]>=k){
52               canuse[i]=true;
53               require[i]=freq[i]/k;
54
55            }
56        }
57
58        //then maxlrn
59        string curr="";
60        for(int l=maxlen;l>=0;l--){
61            vector<int> temprequire=require;
62            if(backtracking(s,curr,temprequire,canuse,l,k))return result;
63
64        }
65        return result;
66    }
67};