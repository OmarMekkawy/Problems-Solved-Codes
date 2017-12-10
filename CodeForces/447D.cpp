#include <bits/stdc++.h>

using namespace std;
int arr[1001][1001];
long long accumilative[2][1000004];
priority_queue<int> PickRow,PickCol;
int main()
{
    int n,m,k,p;
    scanf("%d%d%d%d",&n,&m,&k,&p);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&arr[i][j]);
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=arr[i][j];
        }
        PickRow.push(sum);
    }
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=arr[j][i];
        }
        PickCol.push(sum);
    }
    for(int i=1;i<=k;i++){
        int cur=PickRow.top();
        PickRow.pop();
        accumilative[0][i]=cur+accumilative[0][i-1];
        cur-=p*m;
        PickRow.push(cur);
        cur=PickCol.top();
        PickCol.pop();
        accumilative[1][i]=cur+accumilative[1][i-1];
        cur-=p*n;
        PickCol.push(cur);
    }
    long long mx=LLONG_MIN;
    for(int i=0;i<=k;i++){
        mx=max((long long)mx,(long long)accumilative[0][i]+accumilative[1][k-i]-((long long)i*((long long)k-i)*p));
    }
    printf("%I64d\n",mx);
    return 0;
}
