class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int e,int f, vector<vector<int>>&dp){
            if(e==1 || f<=1 ) return f;
            if(dp[e][f]!=-1) return dp[e][f];
            
            int mnsteps=INT_MAX;
            for(int k=1 ; k<=f ; k++){
                int temp = max(solve(e-1,k-1,dp),solve(e,f-k,dp))+1;
                mnsteps = min(temp,mnsteps);
            }
            return dp[e][f]=mnsteps;
    }
    int eggDrop(int e, int f) 
    {
        // your code here
        vector<vector<int>> dp(201,vector<int>(201,-1));
       return solve(e,f,dp);
    }
};
