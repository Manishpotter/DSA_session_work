class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int ksack(int w,int wt[], int val[],int n,vector<vector<int>> &dp){
        if(n==0){
            if(wt[n]<=w) return val[n];
            else return 0;
        }
        if(dp[n][w]!=-1) return dp[n][w];
        int nottake= 0+ksack(w,wt,val,n-1,dp);
        int take=INT_MIN;
        if(wt[n]<=w)
            take= val[n] + ksack(w-wt[n],wt,val,n-1,dp);
        return dp[n][w]=max(take,nottake);
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(w+1,-1));
       return ksack(w,wt,val,n-1,dp);
    }
};
