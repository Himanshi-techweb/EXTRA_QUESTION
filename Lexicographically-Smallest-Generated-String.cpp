1class Solution {
2public:
3    string generateString(string str1, string str2) {
4       string small;
5       int n=str1.size();
6       int m=str2.size();
7       string result(n+m-1,'0');
8       vector<bool>canchange(n+m-1,true);
9       for(int i=0;i<str1.size();i++){
10         if(str1[i]=='T'){
11            int i_=i;
12            for(int j=0;j<m;j++){
13                if(result[i_]!='0' && result[i_]!=str2[j])return "";
14                result[i_]=str2[j];
15                
16                canchange[i_]=false;
17                i_++;
18            }
19            
20         } 
21       } 
22       for(int i=0;i<n+m-1;i++){
23        if(result[i]=='0')result[i]='a';
24       }
25
26       //check;
27       for(int i=0;i<n;i++){
28        if(str1[i]=='F'){
29            //iterate from back and check if it canchange in between i to i+m then change it from back
30            string str=result.substr(i,m);
31            if(str!=str2)continue;
32            int i_=i+m-1;
33            while(i_>=i && canchange[i_]==false){
34                i_--;
35            }
36            if(i_<i)return "";
37            result[i_]='b';
38        }
39       }
40       return result;
41    }
42};