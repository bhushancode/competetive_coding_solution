#include<bits/stdc++.h>
//bitmasking, dp, recurssion
//DealShare
#define int long long 
using namespace std;

int bitmask=0;
int dp[501][1<<13];
int solve( int i, int bitmask, vector<int> &price, vector<int> &group){
    if(i>=price.size()){
        if(bitmask==1<<group.size()-1)
        return dp[i][bitmask]=0;
        else 
            return INT_MIN;
    }
    
    if(dp[i][bitmask]!=-1) 
        return dp[i][bitmask];
    
    int exc= solve(i+1, bitmask, price, group);
    int inc = 0;
    
    for(int j=0;j<group.size();j++){
        if(bitmask & (1<<j)>0) continue;
        if(i+group[j]>price.size()) continue;
        
        int r=price[i+group[j]-1];
        int l = i==0?0:price[i-1];
        inc = max(inc, r-l + solve(i+group[j], (bitmask | (1<<j)), price, group));
        
    }
    
    return dp[i][bitmask]=max(inc, exc);
}
 void solve(int c) {
     
     int n,m;
     cin>>n>>m;
     vector<int> price(n), group(m);
     
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<m;i++){
        cin>>group[i];
    }
    for(int i=1;i<n;i++){
        price[i]=price[i-1]+price[i];
    }
    
    memset(dp, -1, sizeof(dp));
    
    cout<<solve(0, bitmask, group, price);
    

    return;
 }
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1, c;
    c=0;
    while(t--){
        c++;
        solve(c);
    }
    
    return 0;

 
}
