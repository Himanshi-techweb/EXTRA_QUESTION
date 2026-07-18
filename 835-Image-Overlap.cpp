class Solution {
public:

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();int ans=0;
        for(int row_offset=-n+1;row_offset<n;row_offset++){
            for(int col_offset=-n+1;col_offset<n;col_offset++){
                int cnt=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(row_offset+i >=0 && row_offset+i<n && col_offset+j>=0 && col_offset+j<n && img1[i][j]==1 && img2[row_offset+i][col_offset+j]==1)cnt++;
                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};