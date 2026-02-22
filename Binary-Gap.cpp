1class Solution {
2public:
3    int binaryGap(int n) {
4        int start=-1;int end=0;int ans=0;
5        while(n>0){
6            int rem=n%2;
7            if(rem==1){
8                ans=max(ans,start);
9                start=1;
10            }
11            else if(start!=-1){
12               start++; 
13            }
14            n=n/2;
15        }
16        return ans;
17    }
18};