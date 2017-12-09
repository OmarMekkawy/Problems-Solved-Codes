#include <bits/stdc++.h>

using namespace std;
int arr[2][2];
long long evens[100004],odds[100004];
int main()
{
    string x;
    cin>>x;
    long long evens=0,odds=0;
    for(int i=0;i<x.size();i++){
        odds+=(long long)arr[i%2][x[i]-'a'];
        evens+=(long long)arr[1-(i%2)][x[i]-'a'];
        arr[i%2][x[i]-'a']++;
        odds++;
    }
    cout<<evens<<" "<<odds<<endl;
    return 0;
}
