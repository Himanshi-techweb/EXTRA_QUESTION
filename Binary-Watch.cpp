1class Solution {
2public:
3    vector<int> hour={1,2,4,8};
4    vector<int> minute={1,2,4,8,16,32,64};
5    vector<string> ans;
6    void solve(int m,int currcount,int actualcount,int hourcount,int minutecount){
7        if(currcount>actualcount){
8            return;
9        }
10        if(m>10)return;
11        if(currcount==actualcount){
12            if(hourcount<=11 && minutecount<=59){
13                string str=to_string(hourcount)+':';
14                if(minutecount<10){
15                    str+='0';
16                }
17                str+=to_string(minutecount);
18                ans.push_back(str);
19                // ans.push_back(hourcount+":"+minutecount);
20                return;
21            }
22            
23        }
24        //include current index 
25        if(m<4){
26           solve(m+1,currcount+1,actualcount,hourcount+(1<<m),minutecount);
27        }
28        else{
29            solve(m+1,currcount+1,actualcount,hourcount,minutecount+(1<<(m-4)));
30        }
31
32        solve(m+1,currcount,actualcount,hourcount,minutecount);
33        
34    }
35    vector<string> readBinaryWatch(int turnedOn) {
36        // vector<string> ans;
37        solve(0,0,turnedOn,0,0);
38        return ans;
39    }
40};