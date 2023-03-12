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
    int k; cin>>k;
    vector<vector<int>> m;
    for(int i=0 ; i<k ; i++){
        vector<int> temp;
        for(int j=0 ; j<k ; j++){
            int x; cin>>x;
            temp.push_back(x);
        }
        m.push_back(temp);
    }
    int n=k-1;
   for(int i=0 ; i<=n/2 ; i++ ){
       int a=0,b=0,c=0,d=0;
       for(int j=i ; j<(n-i) ; j++){
          a=m[i][j];
          b=m[n-j][i];
          c=m[n-i][n-j];
          d=m[j][n-i];
        //   cout<<i<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
          m[i][j]=d;
          m[j][n-i]=c;
          m[n-j][i]=a;
          m[n-i][n-j]=b;
       }
   }
   for(int i=0 ; i<k ; i++){
        for(int j=0 ; j<k ; j++){
            cout<<m[i][j]<<" ";
        }
       cout<<endl;
    }
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
