class Solution{
public:
    int dp[501][501];
    int partition(string &s,int i,int j){
        if(i>=j)return dp[i][j]=0;
        if(isPalindrome(s,i,j)){
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1e9;
        for(int k=i ; k<j ; k++){
            ans=min(ans,1+partition(s,i,k)+partition(s,k+1,j));
        }
        return dp[i][j]=ans;
    
    }
    bool isPalindrome(string &s,int i,int k){
       
        while(i<=k){
            if(s[i++]!=s[k--]){
                return false;
            }
        }
        return true;
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return partition(str,0,str.size()-1);
        
    }
};
