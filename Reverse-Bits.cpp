1class Solution {
2public:
3    int reverseBits(int n) {
4      uint32_t r=0;
5      int i=0;
6      while(i<32){
7        r=r<<1;
8        r= r | (n&1);
9        n=n>>1;
10        i++;
11      }  
12      return r;
13    }
14};