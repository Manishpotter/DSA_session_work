#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
const int N=1e7+10;
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
///////////////////////////////////////////////////////////

void dfs(int vertex,int par,vector<vector<int>> &g,vector<int> &subt_sum,vector<int> &val){
    subt_sum[vertex]= val[vertex-1];
    for(auto child : g[vertex]){
        if(child==par) continue;
        dfs(child,vertex,g,subt_sum,val);
        subt_sum[vertex]+=subt_sum[child];
    }
}
vector<bool> isPrime(N,1);
vector<int> lp(N),hp(N);
void seive(){
    isPrime[0]=isPrime[1]=false;
    for(ll i=2 ; i<N ; i++){
        if(isPrime[i]==true){
            lp[i]=hp[i]=i;
            for(ll j=i*2 ; j<N ; j+=i){
                isPrime[j]=false;
                hp[j]=i;
                if(lp[j]==0){
                    lp[j]=i;
                }
            }
        }
    }
}

void solve() {
       ll n1,n2;
       cin>>n1>>n2;
       vector<int> v1,v2(n2);
       for(int i=0 ; i<n1 ; i++){
        ll x;cin>>x;
        v1.push_back(x);
       }
       for(int i=0 ; i<n2 ; i++){
        cin>>v2[i];
       }
       for(int i=0 ; i<n2 ; i++){
        v1.push_back(v2[i]);
       }
       sort(v1.begin(),v1.end());
       cout<<(v1[n1-1]+v1[n1])/2<<endl;
}
int main() {
     
    // your code goes here
    
    ll t;cin>>t;
    seive();
    while(t--){
        solve();
        
    }

    return 0;
}
