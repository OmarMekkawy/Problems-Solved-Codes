#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
int main()
{
    int T,a,b,c,n;
    scanf("%d",&T);
    long long F=1;
    int curmed=1;
    long long sum=1;
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        scanf("%d",&n);
        F=1;
        curmed=1;
        sum=1;
        priority_queue<long long> one,two;
        one.push(1);
        for(int i=1;i<n;i++){
            F=(long long)curmed*a+(long long)b*(i+1)+(long long)c;
            F%=MOD;
            sum+=F;
            if((one.size()+two.size())%2==0&&F>curmed){
                two.push(-F);
                one.push(-two.top());
                two.pop();
            }
            else if((one.size()+two.size())%2==0){
                one.push(F);
            }
            else if((one.size()+two.size())%2&&F<curmed){
                one.push(F);
                two.push(-one.top());
                one.pop();
            }
            else{
                two.push(-F);
            }
            curmed=one.top();
        }
        printf("%lld\n",sum);
    }
}
