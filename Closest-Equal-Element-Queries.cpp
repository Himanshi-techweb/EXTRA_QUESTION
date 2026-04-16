1class Solution {
2public:
3    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
4        int n = nums.size();
5        unordered_map<int, vector<int>> valToIndices;
6        
7        // Step 1: Map values to their sorted indices
8        for (int i = 0; i < n; ++i) {
9            valToIndices[nums[i]].push_back(i);
10        }
11        
12        vector<int> results;
13        for (int qIdx : queries) {
14            int targetVal = nums[qIdx];
15            const vector<int>& indices = valToIndices[targetVal];
16            
17            if (indices.size() <= 1) {
18                results.push_back(-1);
19                continue;
20            }
21            
22            // Step 2: Binary search for neighbors
23            auto it = lower_bound(indices.begin(), indices.end(), qIdx);
24            int pos = distance(indices.begin(), it);
25            
26            int minDist = n; // Initialize with max possible circular distance
27            
28            // Check neighbor to the right
29            int rightIdx = indices[(pos + 1) % indices.size()];
30            int d1 = abs(qIdx - rightIdx);
31            minDist = min({minDist, d1, n - d1});
32            
33            // Check neighbor to the left
34            int leftIdx = indices[(pos - 1 + indices.size()) % indices.size()];
35            int d2 = abs(qIdx - leftIdx);
36            minDist = min({minDist, d2, n - d2});
37            
38            results.push_back(minDist);
39        }
40        
41        return results;
42    }
43};