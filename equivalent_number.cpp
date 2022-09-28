#include <bits/stdc++.h>
using namespace std;
bool solve(){
    int a, b;
    cin>>a>>b;
    
    vector<int> aprime;
    vector<int> bprime;
    vector<int> v1(a+1, 1);
    vector<int> v2(b+1, 1);
    for(int i=2;i<a;i++){
        if(v1[i]==1 && a%i==0) aprime.push_back(i);
        int j=i+i;
        while(j<a){
            v1[j]=0;
            j+=i;
        }
    }
    
    for(int i=2;i<b;i++){
        if(v2[i]==1 && b%i==0) bprime.push_back(i);
        int j=i+i;
        while(j<b){
            v2[j]=0;
            j+=i;
        }
    }
    int x=0;
    if(aprime!=bprime)
        {
            cout<<"No"<<endl;
            return false;
        }
    else{
        map<int, int> mp1;
        map<int, int> mp2;
       for(int i=0;i<a;i++){
           while(a%aprime[i]==0){
               mp1[aprime[i]]++;
               a=a/aprime[i];
           }
       }
       
        for(int i=0;i<b;i++){
           while(b%bprime[i]==0){
               mp2[bprime[i]]++;
               b=b/bprime[i];
           }
           if(x==0) x = gcd(mp1[bprime[i]], mp2[aprime[i]]);
           else if(x !=  gcd(mp1[bprime[i]], mp2[aprime[i]]))
            {
            cout<<"NO"<<endl;
            return false;
                
            }
       }
       
       
    }
    cout<<"YES"<<endl;
    return true;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
