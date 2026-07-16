class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int> q;
        int n=changed.size();
        if(n%2!=0)return {};
        for(int i=0;i<n;i++)q[changed[i]]++;
        sort(changed.begin(),changed.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            int curr=changed[i];
            if(curr==0 && q[curr]%2!=0)continue;
            if(q.count(curr) && q.count(curr*2) && q[curr]>0 && q[curr*2]>0){
                ans.push_back(curr);
                q[curr]--;
                q[curr*2]--;
                if(q[curr]<=0)q.erase(curr);
                if(q[curr*2]<=0)q.erase(curr*2);

            }
        }
        cout<<ans.size()<<endl;
        if(ans.size()!=changed.size()/2)return {};
        return ans;
    }
};