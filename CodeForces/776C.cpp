#include <bits/stdc++.h>

using namespace std;
map<long long,long long> toCnt;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    long long ans=0;
    long long sum=0;
    toCnt[0]++;
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        toCnt[sum+t]++;
        sum+=(long long)t;
        for(long long j=1,r=0;abs(j)<=1000000000000000;j=(long long)j*k,r++){
            if((k==-1&&r==2)||(k==1&&r==1))
                break;
            ans+=(long long)toCnt[sum-j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
