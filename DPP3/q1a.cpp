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
void josephus(ll ind,ll &ans,vector<int> &v,ll k){
    if(v.size()==1){
        ans=v[0];
        return;
    }
    ind = (ind+k)%v.size();
    v.erase(v.begin()+ind);
    josephus(ind,ans,v,k);
}
void solve() {
       ll n,k;
       cin>>n>>k;
       vector<int> v(n);
       unordered_map<int,int> vis;
       for(int i=1 ; i<=n ; i++){
        v[i-1]=i;
       }
    k--;
    ll ans=0;
    josephus(0,ans,v,k);
    cout<<ans<<endl;
    //    while(vis.size()!=(n-1)){
    //         ll c=0,i=0;
    //         while(c!=k){
    //             if(vis.find(v[(i)%n])==vis.end()){
    //                 c++;
    //                 vis[v[(i)%n]]=1;
    //             }
    //             i++;
    //         }
    //    }
    //    for(int i=0 ; i<n ; i++){
    //     if(vis.find(v[i])==vis.end()){
    //         cout<<i<<endl;
    //         break;
    //     }
    //    }
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
