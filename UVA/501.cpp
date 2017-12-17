#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        scanf("%d%d",&M,&N);
        vector<int> inp;
        for(int i=0;i<M;i++){
            int tmp;
            scanf("%d",&tmp);
            inp.push_back(tmp);
        }
        priority_queue<int> one,two;
        int last=0;
        for(int i=1;i<=N;i++){
            int tmp;
            scanf("%d",&tmp);
            while(one.size()+two.size()<tmp){
                while(last<tmp){
                    if(one.size()==0||inp[last]<one.top())
                        one.push(inp[last]);
                    else
                        two.push(-inp[last]);
                    last++;
                }
            }
            while(one.size()>i){
                two.push(-one.top());
                one.pop();
            }
            while(one.size()<i){
                one.push(-two.top());
                two.pop();
            }
            printf("%d\n",one.top());
        }
        if(T!=0)
        printf("\n");
    }
    return 0;
}
