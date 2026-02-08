1class Solution {
2public:
3    int minimumDeletions(string s) {
4        int size=s.size();
5        
6
7        vector<int> a_count(size);
8        vector<int> b_count(size);
9        int count_b=0;int count_a=0;
10        for(int i=0;i<size;i++){
11           b_count[i]=count_b;
12           if(s[i]=='b')count_b++;
13        }
14
15        for(int i=size-1;i>=0;i--){
16           a_count[i]=count_a;
17           if(s[i]=='a')count_a++;
18        }
19
20
21
22        int ans=INT_MAX;
23        for(int i=0;i<size;i++){
24            ans=min(ans,a_count[i]+b_count[i]);
25        }
26        return ans;
27    }
28};