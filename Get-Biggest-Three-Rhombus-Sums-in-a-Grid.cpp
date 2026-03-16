1class Solution {
2public:
3    vector<int> getBiggestThree(vector<vector<int>>& grid) {
4        int m=grid.size();
5        int n=grid[0].size();
6    //    priority_queue<int,vector<int> ,greater<int>> q;
7    priority_queue<int>q;
8       for(int i=0;i<m;i++){
9        for(int j=0;j<n;j++){
10            //for each index check sum 
11           q.push(grid[i][j]);
12            int k=1;
13            //check k if it correct
14            for(;;k++){
15                if(i+2*k>=m)break;
16                if(j-k<0)break;
17                if(j+k>=n)break;
18  
19                int sum=0;
20                for(int t=0;t<k;t++)sum+=grid[i+t][j+t];
21                for(int t=0;t<k;t++)sum+=grid[i+k+t][j+k-t];
22                for(int t=0;t<k;t++)sum+=grid[i+2*k-t][j-t];
23                for(int t=0;t<k;t++)sum+=grid[i+k-t][j-k+t];
24
25                q.push(sum);
26                cout<<sum<<endl;
27            }
28
29            //check sum in 
30            
31        }
32       } 
33       vector<int> ans;
34       int k=0;
35       set<int> st;
36       while(!q.empty()){
37        // if(ans.empty())ans.push_back(q.top());
38        // else if(!ans.empty() && ans.back()!=q.top()){
39        //    ans.push_back(q.top());
40        // }
41        // q.pop();
42        st.insert(q.top());
43        q.pop();
44        if(st.size()==3)break;
45       }
46       for(auto it:st)ans.push_back(it);
47       reverse(ans.begin(),ans.end());
48       return ans;
49    }
50};