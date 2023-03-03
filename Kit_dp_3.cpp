#include <string>
#include <vector>
#include <iostream>
#define div 1000000007
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i=2;i<=n;i++) dp[i][1]=1;
    for(int j=2;j<=m;j++) dp[1][j]=1;
    for(int i=0;i<puddles.size();i++){
        int x=puddles[i][0], y=puddles[i][1];
        dp[y][x]=0;
        if(x==1){
            for(int j=y;j<=n;j++) dp[j][1]=0;
        }
        if(y==1){
            for(int j=x;j<=m;j++) dp[1][j]=0;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(!dp[i][j]) continue;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=div;
        }
    }
    answer=dp[n][m];
    return answer;
}
