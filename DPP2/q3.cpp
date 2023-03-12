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
    string s;cin>>s;
    int n=s.size();
    string ans="";
    vector<int> v={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    map<int,string>mp;
    mp.insert({2,"ABC"});
    mp.insert({3,"DEF"});
    mp.insert({4,"GHI"});
    mp.insert({5,"JKL"});
    mp.insert({6,"MNO"});
    mp.insert({7,"PQRS"});
    mp.insert({8,"TUV"});
    mp.insert({9,"WXYZ"});
    for(int i=0 ; i<n ; i++){
        if(s[i]!=' '){
            for(int j=0 ; j<mp[v[s[i]-'A']].size() ; j++){
                ans+=v[s[i]-'A']+'0';
                if(s[i]==mp[v[s[i]-'A']][j])
                    break;
            }
        }else
            ans+=0+'0';
    }
    
    cout<<ans<<endl;
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
