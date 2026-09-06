class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
    int findparent(int node){
        if(node==parent[node])return node;
        return parent[node]=findparent(parent[node]);
    }
    void unite(int x,int y){
        int px=findparent(x);
        int py=findparent(y);
        if(px==py)return;
        if(rank[px]<rank[py]){
            parent[px]=py;
        }
        else if(rank[px]>rank[py])parent[py]=px;
        else {
            parent[px]=py;
            rank[py]++;
        }
    }

};
class Solution {
public:
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> st;
        int n=accounts.size();
        DSU dsu(n);
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(st.find(accounts[i][j])!=st.end()){
                    dsu.unite(i,st[accounts[i][j]]);
                }
                else st[accounts[i][j]]=i;
            }
        }
        vector<vector<string>> arr(n);
        for(auto it:st){
            auto str=it.first;
            auto i=it.second;
            int x=dsu.findparent(i);
            arr[x].push_back(str);
        }

        for(int i=0;i<n;i++){
            sort(arr[i].begin(),arr[i].end());
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            auto str=accounts[i][0];
            if(arr[i].size()>0){

            vector<string> newans;
            newans.push_back(str);
            for(auto it:arr[i])newans.push_back(it);
            ans.push_back(newans);
            }
        }
        return ans;
    }
};