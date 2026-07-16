class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> right(nums.size(),0);
        int l=0;
        int total=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++){
            int r=total-l-nums[i];
            if(l==r)return i;
            l=l+nums[i];

        }
        return -1;

    }
};