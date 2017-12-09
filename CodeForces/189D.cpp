#include <bits/stdc++.h>

using namespace std;
int DP[61][61][61];
int MinDist[61][61][61];
int main()
{
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    for(int i=0;i<m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                scanf("%d",&DP[i][j][k]);
                MinDist[0][j][k]=DP[i][j][k];
            }
        }
    }
    for(int r=0;r<m;r++){
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    DP[r][i][j]=min(DP[r][i][j],DP[r][i][k]+DP[r][k][j]);
                    MinDist[0][i][j]=min(MinDist[0][i][j],DP[r][i][j]);
                }
            }
        }
    }
    for(int res=1;res<=60;res++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                MinDist[res][i][j]=1e9;
                for(int k=1;k<=n;k++){
                    MinDist[res][i][j]=min(MinDist[res][i][j],MinDist[0][i][k]+MinDist[res-1][k][j]);
                }
            }
        }
    }
    for(int i=0;i<r;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",MinDist[min(c,60)][a][b]);
    }
    return 0;
}
