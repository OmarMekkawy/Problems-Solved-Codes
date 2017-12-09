#include <bits/stdc++.h>

using namespace std;
int DP[2][200001];
#define MOD 1000000007

int main()
{
    int x,y;
    cin>>x>>y;
    int z=x+y;
    int mx=1;
    for(int i=1;i<=900;i++){
       if(i*(i+1)/2<=z)
            mx=max(mx,i);
       else
        break;
    }
    for(int i=0;i<=200001;i++)
        DP[0][i]=1;
    for(int i=1;i<=mx;i++){
        for(int j=0;j<=x;j++){
            int alPut=mx*(mx+1)/2-i*(i+1)/2;
            int k=y-(alPut-(x-j));
            if(k>y)
                continue;
            DP[i%2][j]=0;
            if(j>=i)
                DP[i%2][j]+=DP[(i+1)%2][j-i];
            if(k>=i)
                DP[i%2][j]+=DP[(i+1)%2][j];
            DP[i%2][j]%=MOD;
        }
    }
    cout<<DP[mx%2][x]<<endl;
    return 0;
}
