#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
multiset<int> ToGetMed;
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
        ToGetMed.insert(1);
        F=1;
        curmed=1;
        sum=1;
        for(int i=1;i<n;i++){
            F=(long long)curmed*a+b*(i+1)+c;
            F%=MOD;
            sum+=F;
            ToGetMed.insert(F);
            if(ToGetMed.size()%2==0&&F<curmed){
                set<int>::iterator it=ToGetMed.lower_bound(curmed);
                it--;
                curmed=*it;
            }
            else if(ToGetMed.size()%2&&F>curmed){
                set<int>::iterator it=ToGetMed.upper_bound(curmed);
                curmed=*it;
            }
        }
        printf("%lld\n",sum);
        ToGetMed.clear();
    }
}
