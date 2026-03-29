1class Solution {
2public:
3    string findTheString(vector<vector<int>>& lcp) {
4        int n=lcp.size();
5        string s(n,'\0');
6        if(lcp[0][0]!=n)return "";
7        //current index of string i
8        int i=0;
9        vector<int> arr(26,0);
10        // for(int i=0;i<n;i++){
11        //     for(int j=0;j<n;j++){
12        //         //abca n=4 and i=1 then i_len n-i
13        //         int i_len=n-i;
14        //         int j_len=n-j;
15        //         if(lcp[i][j]>min(i_len,j_len))return "";
16        //         if(lcp[i][j]!=lcp[j][i])return "";
17        //     }
18        // }
19        while(i<n){
20           //for first index fill it with 'a' only
21            if(i==0)s[i]='a';
22           //then after it from next index check if j(0 to i-1) is not equal to 0 if not then fill it with same character as j as increase i
23            else{
24               //int j=0;
25                vector<bool> forbidden(26,false);
26                int j=0;
27                while(j<i && lcp[i][j]==0){
28                forbidden[s[j]-'a']=true;
29                j++;
30                }
31                if(j<i){
32                    s[i]=s[j];
33                }
34                else{
35                   char ch='$';
36                   for(int k=0;k<26;k++){
37                   if(!forbidden[k]){
38                    ch=k+'a';
39                    break;
40                   }
41                   }
42                   if(ch=='$')return "";
43                   s[i]=ch;
44                }
45               
46
47            }
48            i++;
49        }
50        //verify string lcp
51        for(int i=0;i<n;i++){
52            for(int j=0;j<n;j++){
53                int cnt=0;int x=i;int y=j;
54                while(x<n && y< n && s[x]==s[y]){
55                   x++;y++;cnt++;
56                }
57                if(lcp[i][j]!=cnt)return "";
58            }
59        }
60        return s;
61    }
62};