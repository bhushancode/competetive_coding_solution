#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(int testcase){
    int n;
    list<int> nums;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        
        cin>>temp;
        nums.push_back(temp);
    }
    
    int ans=0;
    while(!is_sorted(nums.begin(), nums.end())){
        auto it = nums.begin();
        for(int i=0;i<n;i++){
            int a= *it;
            ++it;
            int b= *it;
            // cout<<a<<" "<<b<<endl;
            if(a>b)
              { 
                nums.erase(it);
                
                nums.push_front(b);
                // cout<<*(++it)<<" "<<i<<" "<<b<<" "<<*nums.begin()<<endl;
                ans++;
              }
        }
        
        // cout<<endl;
    }
    cout<<ans<<endl;
    
    return;
}

int main() {
	// your code goes here
	
	int t=1, testcase=0;
	cin>>t;
	
	while(t--){
	    testcase++;
	    solve(testcase);
	}
	return 0;
}
