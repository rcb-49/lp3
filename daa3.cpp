#include<bits/stdc++.h>
using namespace std;

// 3  2  5    W = 6
// 30 40 60
int f(int ind,int w,vector<int> &weight,vector<int> &value,vector<vector<int>> &dp){
    // base

    if(ind ==0){
        if(w>=weight[ind]) return value[ind];
        else return 0;
    }

    if(dp[ind][w] !=-1) return dp[ind][w];

    int notpick = 0 + f(ind-1,w,weight,value,dp);
    int pick = INT_MIN;

    if(w>=weight[ind]){
        pick = value[ind] + f(ind-1,w-weight[ind],weight,value,dp);
    }

    return dp[ind][w] = max(notpick,pick);

}

int main(){
    int n,W;
    
    cout<<"Enter n :";
    cin>>n;
    cout<<endl;
    vector<int> weight(n),value(n);
    cout<<"Enter knapsack capacity :";
    cin>>W;
    cout<<endl;
    cout<<"Enter weights :\n";
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<"Enter values :\n";
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    cout<<endl;

    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));

    int ans = f(n-1,W,weight,value,dp);
    cout<<"Ans :"<<ans;
    return 0;
}