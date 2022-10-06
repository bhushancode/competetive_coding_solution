#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;
//intuition check if any element has more than 3 adjacent rows or cols store it' {i, j} and later make all i, j as 0
bool countnum(vector<vector<int>> &nums, int k, int i, int j){
    int m=nums.size();
    int n=nums[0].size();
    int rowcount=0, colcount=0;
    int i1, i2, j1, j2;
    for(int a=i; a>=0 ;a--){
        if(nums[a][j]==k) { i1=a; rowcount++;}
        else { break;}
    }
    for(int a=i; a<m ;a++){
        if(nums[a][j]==k) {i2 = a; rowcount++;}
        else { break;}
    }
    rowcount--;
    
    for(int a=j; a>=0 ;a--){
        if(nums[i][a]==k) { j1 = a; colcount++;}
        else{ break;}
    }
    for(int a=j; a<n ;a++){
        if(nums[i][a]==k) { j2 = a; colcount++;}
        else{ break;}
    }
    colcount--;
    
    if(rowcount>=3 || colcount>=3) return true;
    else return false;
  
}

void solve(int testcase){
    int m, n;
    cin>>m>>n;
    vector<vector<int>> nums(m, vector<int>(n,0));
    vector<pair<int, int>> ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           if(nums[i][j]!=0 && countnum(nums, nums[i][j], i, j)) 
            ans.push_back({i, j});
        }
    }
    
    for(int i=0;i<ans.size();i++){
        nums[ans[i].first][ans[i].second]=0;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return;
}

int32_t main() {
	// your code goes here
	
	int t=1, testcase=0;
	cin>>t;
	
	while(t--){
	    testcase++;
	    solve(testcase);
	}
	return 0;
}
