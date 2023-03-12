#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
const int N=1e5+10;
const int M=1e9+7;
vector<int> g[N];
int par[N];
void dfs(ll vertex , ll p=-1){
    par[vertex]=p;
    for(auto child : g[vertex]){
        if(child==p) continue;
        dfs(child,vertex);
    }
}
vector<ll> path(ll v){
    vector<ll> ans;
    while(v!=-1){
        ans.push_back(v);
        v=par[v];
    }
    return ans;
}
ll stringTointeger(string str)
{
    ll temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}
vector<int> lps(string &s){
	int n=s.size();
	vector<int> LPS(n);
	int len=0;
	for(int i=1 ; i<n ; ){
		if(s[i]==s[len]){
			len++;
			LPS[i]=len;
			i++;
		}else{
			if(len==0){
				LPS[i]=0;
				i++;
			}else{
				len=LPS[len-1];
			}
		}
	}
	return LPS;
	// for(int i=1 ; i<=n ; i++){
    	// 	string t=s.substr(0,i),a="",b="",p;
    	// 	// cout<<t<<endl;
    	// 	int k=t.size(),mx=0;
    	// 	for(int j=0 ; j<k ; j++){
    	// 		if(a==p && (a.size()<k)){
    	// 			mx=max(mx,int(a.size()));
    	// 		}
    	// 		a+=t[j];
    	// 		b+=t[k-1-j];
    	// 		p=b;
    	// 		reverse(p.begin(),p.end());
    	// 		// cout<<a<<" "<<b<<endl;
    	// 	}
    	// 	// cout<<mx<<endl;
    	// 	lps[i-1]=mx;
    	// }
}

void KPM(){
	string txt,pat;cin>>txt>>pat;
    	int m=pat.length(),n=txt.size();
    	vector<int> LPS;
    	LPS=lps(pat);
    	//KMP
    	int i=0,j=0;
    	while(i<n){
    		if(txt[i]==pat[j]){
    			i++;j++;
    		}
    		if(j==m){
    			cout<<(i-j)<<" ";
    		}else if(i<n && pat[j]!=txt[i]){
    			if(j!=0){
    				j=LPS[j-1];
    			}else{
    				i=i+1;
    			}
    		}
    	}
}
///////////////////////////////////////////////////////////

void dfs(int vertex,int par,vector<vector<int>> &g,vector<int> &subt_sum,vector<int> &val){
    subt_sum[vertex]= val[vertex-1];
    for(auto child : g[vertex]){
        if(child==par) continue;
        dfs(child,vertex,g,subt_sum,val);
        subt_sum[vertex]+=subt_sum[child];
    }
}
ll fact(ll n,ll &k){
    if(n==0) return 1;
    k=k*n;
    fact(n-1,k);
}
void solve() {
    	ll n;cin>>n;
        ll k=1;
        fact(n,k);
        cout<<k<<endl;
}
int main() {
	 
	// your code goes here
    ll t;cin>>t;
    while(t--){
     	solve();
    }
    return 0;
}
