1class Solution {
2public:
3    int m,n;
4    vector<pair<int,int>> rc={{0,1},{1,0}};
5    vector<vector<vector<int>>> dp;
6    // int coin(int i,int j,vector<vector<int>> &coins,int neu){
7    //     if(i>=m || j>=n)return INT_MIN;
8    //     if(i==m-1 && j==n-1){
9    //         if(coins[i][j]>=0)return dp[i][j][neu]=coins[i][j];
10    //         else {
11    //             if(neu>0)return dp[i][j][neu]= max(0,coins[i][j]);
12    //             return dp[i][j][neu]= coins[i][j];
13    //         }
14    //     } 
15    //     if(dp[i][j][neu]!=-1)return dp[i][j][neu];
16    //     int ans=INT_MIN;
17    //     int next=0;
18    //     for(auto it:rc){
19    //         int nr=it.first+i;
20    //         int nc=it.second+j;
21    //         if(nr<m && nc<n){
22    //            next=coin(nr,nc,coins,neu);
23    //            if(next!=INT_MIN)
24    //            {if(coins[i][j]>=0)ans=max(ans,next+coins[i][j]);
25    //            else{
26    //              ans=max(ans,coins[i][j]+next);
27    //              if(neu>0){
28    //                 int next2=coin(nr,nc,coins,neu-1);
29    //                 ans=max(next2,ans);
30    //              }
31    //            }
32    //            }
33    //         }
34    //     }
35    //     // if(dp[i][j])
36    //     //if negative then neu 
37       
38    //     return dp[i][j][neu]=ans;
39
40
41    // }
42    int maximumAmount(vector<vector<int>>& coins) {
43        m=coins.size();n=coins[0].size();
44        dp.assign(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
45        // return coin(0,0,coins,2);
46        for(int k=2;k>=0 ;k--){
47            if(coins[m-1][n-1]>0)dp[m-1][n-1][k]=coins[m-1][n-1];
48            else{
49                if(k>0)dp[m-1][n-1][k]=max(0,coins[m-1][n-1]);
50                else dp[m-1][n-1][k]=coins[m-1][n-1];
51            }
52        }
53
54        for(int i=m-1;i>=0 ;i--){
55            for(int j=n-1;j>=0;j--){
56                if(i==m-1 && j==n-1)continue;
57                for(int k=0;k<=2;k++){
58                    int best=INT_MIN;
59                    if(j+1<n){
60                        int next=dp[i][j+1][k];
61                        if(next!=INT_MIN){
62                            if(coins[i][j]>=0)best=max(best,coins[i][j]+next);
63                            else{
64                                best=max(best,coins[i][j]+next);
65                                if(k>0){
66                                    int next2=dp[i][j+1][k-1];
67                                    if(next2!=INT_MIN)best=max(best,next2);
68                                }
69                            }
70                        }
71                    } 
72
73                    if(i+1<m){
74                        int next=dp[i+1][j][k];
75                        if(next!=INT_MIN){
76                            if(coins[i][j]>=0)best=max(best,next+coins[i][j]);
77                            else{
78                                best=max(next+coins[i][j],best);
79                                if(k>0){
80                                    int next2=dp[i+1][j][k-1];
81                                    if(next2!=INT_MIN)best=max(best,next2);
82                                }
83                            }
84                        }
85                    }
86
87                    dp[i][j][k]=best;
88                }
89            }
90        }
91        return dp[0][0][2];
92    }
93};