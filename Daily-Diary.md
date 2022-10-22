Day 22
## Make all 1 consistent

```
void solve(int testcase){
    string s;
    cin>>s;
    
    int res = 0;
    int countR = 0;
    int totalR = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='R') totalR++;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='R') countR++;
        else{
            res+=min(countR, totalR-countR);
        }
    }
    
    cout<<res<<endl;
    
    return;
}
```

Day 21 October
## DIGIT DP problem and patterns

```

//Number of number X no more than n, whos digit sum is = 17
int n, sum, len;
int dp[101][181][2];
int helper( string &s, int size, int sum, bool tight){
    
    if(sum<0 || size<0) return 0;
    if(size==0){
        if(sum==0) return 1;
        return 0;
    }
    
    if(dp[size][sum][tight]!=-1)
    return dp[size][sum][tight];
    
    int res =0;
    int ub = tight>0?s[s.size()-size]-'0':9;
    
    for(int i = 0; i <= ub; i++){
    	//(tight && (i==ub)), if incoming tight ==1 then and i is upper bound limt then in next recursion we need to pass tight so that number doesn't increase then actual number
        res+=helper(s, size-1, sum-i, (tight && (i==ub)) );
    }
    
    return dp[size][sum][tight]=res;
}

void solve(int testcase){
    
    cin>>n>>sum;
    string s = to_string(n);
    len = s.size();
    memset(dp, -1, sizeof(dp));
    //Above dp represent 3 states, n is nth digit of number X from right, 18 represent total required sum, 2 is state of tight/!tight
    //dp[2][7][1] represent number of numbers X, whose digit sum is 7, 
    
    int ans = helper(s, len, sum, 1);
    cout<<ans<<endl;
    return;
}


```

### https://www.geeksforgeeks.org/queries-for-elements-greater-than-k-in-the-given-index-range-using-segment-tree/
```
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;

vector<int> trees[40001];
int query(vector<int> *trees, int index, int i, int j, int l, int r, int k){
    // cout<<"query"<<i<<j<<endl;
    if(i<l || j>r){
        return 0;
    }
    if(i>=l && j<=r)
        return (trees[index].size()- (lower_bound(trees[index].begin(), trees[index].end(), k)-trees[index].begin()));
   
    int mid = (i+j)/2;
    return query(trees, 2*index+1, i, mid, l, r,k)+ query(trees, 2*index+2, mid+1, j, l,r,k);
    
        
}
vector<int> merge(vector<int> &a, vector<int> &b){
 int i=0, j=0;
 vector<int> v;
 while(i<a.size() && j<b.size()){
     if(a[i]<=b[j]){
         v.push_back(a[i++]);
     }
     else{
         v.push_back(b[j++]);
     }
 }
 
 for(int x=i;x<a.size();x++){
     v.push_back(a[x]);
 }
 
  for(int x=j;x<b.size();x++){
     v.push_back(b[x]);
 }
 
 return v;
}

void buildTree(vector<int> *trees,vector<int> &nums, int index, int i, int j){
    cout<<"Building"<<i<<" "<<j<<endl;
    if(i==j)
        {
        trees[index].push_back(nums[i]);
        return;
            
        }
    int mid = i +(j-i)/2;
    buildTree(trees, nums, index*2+1, i, mid);
    buildTree(trees, nums, 2*index+2, mid+1, j);
    
    trees[index] = merge(trees[2*index+1], trees[2*index+2]);
    return;
        
}

void solve(int testcase){
    int n,m;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>m;
    vector<vector<int>> queries(m);
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        queries[i] = {a, b, c};
    }
    cout<<m<<" "<<n<<"Input"<<endl;
    buildTree(trees,nums, 0, 0, n-1);
    cout<<"Tree Build"<<endl;
    
    for(int i=0;i<m;i++){
        // cout<<queries[i][0]<<queries[i][1]<<endl;
        cout<<query(trees, 0, queries[i][0], queries[i][1], 0, n-1, queries[i][2])<<endl;
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

```
