1class Solution {
2public:
3    int largestSubmatrix(vector<vector<int>>& matrix) {
4        int m=matrix.size();int n=matrix[0].size();
5        //stack vertical height
6        for(int i=0;i<m;i++){
7            for(int j=0;j<n;j++){
8                if(matrix[i][j]==1 &&  i>0){
9                    matrix[i][j]+=matrix[i-1][j];
10                }
11            }
12        }
13
14        //sort row by height of column
15        for(int i=0;i<m;i++){
16            sort(matrix[i].begin(),matrix[i].end(),greater<int>());
17        }
18
19        //begin to calculate area by increasing width 
20        int maxarea=INT_MIN;
21        for(int i=0;i<m;i++){
22            for(int j=0;j<n;j++){
23                maxarea=max(maxarea,matrix[i][j]*(j+1));
24            }
25        }
26        return maxarea;
27    }
28};