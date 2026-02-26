1class Solution {
2public:
3    void add(string &s){
4        //add 1
5        for(int i=s.size()-1;i>=0;i--){
6          if(s[i]=='1')s[i]='0';
7          else {
8            s[i]='1';
9            return;
10          }  
11        }
12        s='1'+s;    
13    }
14    int numSteps(string s) {
15        int x=0;
16        while(s!="1"){
17           
18           //odd;
19           if(s.back()=='0')s.pop_back();
20           else add(s);
21           
22           x++;
23        }
24        return x;
25    }
26};