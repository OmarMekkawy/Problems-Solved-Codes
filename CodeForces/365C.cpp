#include <bits/stdc++.h>

using namespace std;
unordered_map<int, long long>  cnt;
int main()
{
    long long ans=0;
    int a;
    scanf("%d",&a);
    string x;
    cin>>x;
    for(int i=0;i<x.size();i++){
        long long cnt1=0;
        for(int j=i;j<x.size();j++){
            cnt1+=x[j]-'0';
            cnt[cnt1]++;
        }
    }
    for(int i=0;i<x.size();i++){
        long long cnt1=0;
        for(int j=i;j<x.size();j++){
            cnt1+=x[j]-'0';
            if(cnt1!=0&&a%cnt1==0&&a!=0){
                ans+=(long long)cnt[a/cnt1];
            }
            else if(a==0&&cnt1!=0)
                ans+=cnt[0];
            else if(a==0&&cnt1==0)
                ans+=x.size()*(x.size()+1)/2;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
