#include <bits/stdc++.h>

using namespace std;
int cnt[26];
int main()
{
    string x;
    cin>>x;
    for(int i=0;i<x.size();i++){
        cnt[x[i]-'a']++;
    }
    long long ans=0;
    for(int i=0;i<x.size();i++){
        cnt[x[i]-'a']--;
        ans+=(long long)x.size()-i-1LL-(long long)cnt[x[i]-'a'];
    }
    cout<<ans+1LL<<endl;
    return 0;
}
