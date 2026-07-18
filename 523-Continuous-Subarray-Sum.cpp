class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> q;
       q[0]=-1;
       int sum=0;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        int r=sum%k;
        if(q.count(r)){if(i-q[r]>1)return true;}
        else q[r]=i;
       }
       return false;
       
    }
};