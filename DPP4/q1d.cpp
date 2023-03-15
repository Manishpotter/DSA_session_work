int LCS(string &s1,string &s2,int n,int m,vector<vector<int>> &dp){
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n-1]==s2[m-1])
        return dp[n][m]= 1+LCS(s1,s2,n-1,m-1,dp);
    return dp[n][m] = max(LCS(s1,s2,n-1,m,dp),LCS(s1,s2,n,m-1,dp));
}
class Solution
{
    public:

    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
       return LCS(s1,s2,x,y,dp);
    }
};
