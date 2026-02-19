1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4    
5      int prev_s=0;int prev_e=0;
6      int curr_s=0;
7      int i=1;int count=0;
8      while(i<s.size()){
9         if(s[i]!=s[prev_s])break;
10         i++;
11      }
12      prev_e=i-1;
13      curr_s=i;
14      while(i<s.size()){
15        if(s[i]!=s[curr_s]){
16           count+= min(prev_e-prev_s+1,i-curr_s);
17           prev_s=curr_s;
18           prev_e=i-1;
19           curr_s=i;
20        }
21        i++;
22      }
23      count+= min(prev_e-prev_s+1,i-curr_s);
24      return count;  
25    }
26};