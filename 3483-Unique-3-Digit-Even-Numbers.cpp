class Solution {
public:
    unordered_set<int> st;
    void solve(int i,int cnt,int mask,vector<int>&arr,int num){
        if(cnt==3){
            st.insert(num);
            return;
        }
        if(i>=arr.size())return;
        for(int k=0;k<arr.size();k++){
            //take it only if it is not in mask 
            if((mask & (1<<k))==0){
                int newmask=mask;
                int newnum=(num*10)+arr[k];
                newmask|=(1<<k);
                if(cnt==0 && arr[k]!=0){
                    solve(i+1,cnt+1,newmask,arr,newnum);
                }
                else if(cnt==1 ){
                    solve(i+1,cnt+1,newmask,arr,newnum);
                }
                else if(cnt==2 && arr[k]%2==0){
                    solve(i+1,cnt+1,newmask,arr,newnum);
                }
            }
        }
            //so if take it then change it mask 
            solve(i+1,cnt,mask,arr,num);
            //not take it
        

    }
    int totalNumbers(vector<int>& digits) {
        int num=0;
        int mask=0;
        solve(0,0,mask,digits,num);
        return st.size();
    }
};