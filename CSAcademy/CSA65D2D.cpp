#include <bits/stdc++.h>

using namespace std;
vector<int> minEnd;
long long acc[100005];
long long dp[100005];
#define MOD 1000000007
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    minEnd.assign(n+3,n+1);
    for(int i=0;i<q;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        minEnd[a-1]=min(minEnd[a-1],b);
    }
    for(int i=n-1;i>=0;i--)
        minEnd[i]=min(minEnd[i],minEnd[i+1]);
    dp[n+1]=1;
    acc[n+1]=1;
    for(int i=n;i>=0;i--){
        dp[i]=acc[i+1]-acc[minEnd[i]+1];
        dp[i]%=MOD;
        dp[i]+=MOD;
        dp[i]%=MOD;
        acc[i]=acc[i+1]+dp[i];
        acc[i]%=MOD;
    }
    printf("%lld\n",dp[0]);
    return 0;
}
