#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> arr(n+1,1000000000);
    arr[0]=-1;
    int mx=1;
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        int idx=lower_bound(arr.begin(),arr.end(),tmp)-arr.begin();
        mx=max(mx,idx);
        arr[idx]=tmp;
    }
    printf("%d\n",mx);
    return 0;
}
