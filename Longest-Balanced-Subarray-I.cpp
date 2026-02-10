1class Solution {
2public:
3    int longestBalanced(vector<int>& nums) {
4        int ans=0;
5        vector<int> check(1e5 + 5 ,-1);
6        for(int i=0;i<nums.size();i++){
7        int even=0;int odd=0;
8        for(int j=i;j<nums.size();j++){
9            if(check[nums[j]]<i){
10               check[nums[j]]=i;
11               if(nums[j]%2==0)even++;
12               else odd++;
13            }   
14            if(even==odd)ans=max(ans,j-i+1);
15        }
16        
17      }
18      return ans;
19    }
20};