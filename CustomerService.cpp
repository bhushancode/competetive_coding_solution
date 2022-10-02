
//Chalo Question 2022 q1

#include <bits/stdc++.h>

using namespace std;

void solve(int testcase){
    int n, w, k;
    cin>>n>>k>>w;
    vector<int> ans(n);
    
    vector<pair<int, int>> order ;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        order.push_back({a, b});
    }

    //Map store {order time, {orderes}}
    map<int, vector<pair<int, int>>> mp;
    map<pair<int, int>, int> idxmp;
    idxmp[{order[0].second, order[0].first}]=0;
    for(int i=1;i<n;i++){
        idxmp[{order[i].second, order[i].first}]=i;
        mp[order[i].first].push_back({order[i].second, order[i].first});
    }
    
    
    
    int t=order[0].first;
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
    pq.push({order[0].second, order[0].first});
    
    while(n){
        // cout<<n<<"d"<<endl;
        if(!pq.empty())
        {
            // cout<<"PQ-Order";
            pair<int, int> p= pq.top();
            int index = idxmp[p];
            // cout<<p.first<<" "<<p.second<<" "<<index<<endl;
            if(w*(t-p.second)>k*p.first) {
                ans[index]=0; t+=p.first;
                
            }
            else{
                ans[index]= (k*p.first - w*(t-p.second));
                t += p.first;
            }
                n--;
            pq.pop();
        }
        // cout<<"PQ-Popped";
        vector<int> done;
        for(auto e:mp){
            if(e.first<=t+1){
                // cout<<"Order waiting";
                for(auto d:e.second){
                    pq.push(d);
                }
                done.push_back(e.first);
                // cout<<"mp-Erase";
            }
            
        }
        
        for(int j=0;j<done.size();j++)
            mp.erase(done[j]);
        
        if(pq.empty()) t++;
        // cout<<"PQ-Order-Pushed";
        
        
    }
    
    for(int i=0;i<ans.size();i++)
	    cout<<ans[i]<<" ";
    cout<<endl;
 
    
    
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
