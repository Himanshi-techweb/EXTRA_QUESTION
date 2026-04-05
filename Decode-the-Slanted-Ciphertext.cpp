1class Solution {
2public:
3    string decodeCiphertext(string encodedText, int rows) {
4        int cols=encodedText.size()/rows;
5        if(encodedText.size()==0)return "";
6        vector<vector<char>> arr(rows,vector<char>(cols));
7        int k=0;
8        // for(int i=0;i<rows;i++){
9        //     for(int j=0;j<cols;j++){
10        //         arr[i][j]=encodedText[k++];
11        //     }
12        // }
13
14
15        //traverse from 0,0 to row-1,col-1
16        string str="";
17
18        //start of each must be row 0 then increase row by 1 col by 1
19        //
20        for(int j=0;j<cols;j++){
21            int i=0;int k=j;
22            // if(j!=0 && arr[0][j]==' ')break;
23            while(i<rows && k<cols){
24                str.push_back(encodedText[(i*cols +k)]);
25                i++;k++;
26            }
27        }
28        int i=str.size()-1;
29        while(str.back()==' '){
30            str.pop_back();
31        }
32        // for(int k=0;k<i;k++)cout<<str[k];
33        
34        return str;
35    }
36};