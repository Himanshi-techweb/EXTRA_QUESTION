class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
       
       vector<int> ans(queries.size(),0);
       vector<int> prefix(arr.size()+1,0);
       for(int i=0;i<arr.size();i++){
        prefix[i+1]=prefix[i]^arr[i];
       }
       for(int i=0;i<queries.size();i++){
           int l=queries[i][0];int r=queries[i][1];
           ans[i]=(prefix[r+1]^prefix[l]);
       }
       return ans;

    }
};