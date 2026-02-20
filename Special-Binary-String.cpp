1class Solution {
2public:
3   
4    string solve(string &s){
5
6        vector<string> arr;
7        int sum=0;
8        int start=0;
9        for(int i=0;i<s.size();i++){
10            sum+=(s[i]=='1'?1:-1);
11            if(sum==0){
12                string str=s.substr(start+1,i-start-1);
13                start=i+1;
14                str="1"+solve(str)+"0";
15                arr.push_back(str);
16            }
17        }
18        sort(arr.begin(),arr.end(),greater<string>());
19        string result;
20        for(auto it:arr){
21            result=result+it;
22        }
23        return result;
24    }
25    string makeLargestSpecial(string s) {
26        return solve(s);
27    }
28};