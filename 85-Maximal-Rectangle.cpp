class Solution {
public:
    int m,n;
        vector<int> pse(vector<int> &arr){
        vector<int> t(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            t[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return t;
    }
    vector<int> nse(vector<int> &arr){
        vector<int> t(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            t[i]=(st.empty())?arr.size():st.top();
            st.push(i);
        }
        return t;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> psearr=pse(heights);
        vector<int> nsearr=nse(heights);
        int ans=0;
        
        for(int i=0;i<heights.size();i++){
            int l=i-psearr[i];
            int r=nsearr[i]-i;
            ans=max(ans,(l+r-1)*heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        m=matrix.size();n=matrix[0].size();
        // vector<vector<int>> cnt(m,vector<int>(n,0));
        vector<int> height(n);
        int ans=0;
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')height[j]++;
                else height[j]=0;
                
            }
            ans=max(ans,largestRectangleArea(height));
        }

        
        return ans;
    }
};