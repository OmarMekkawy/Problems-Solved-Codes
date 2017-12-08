#include <bits/stdc++.h>

using namespace std;
struct edge
{
    int f,t,nxt;
    edge(int f,int t,int nxt): f(f), t(t), nxt(nxt){}
};
int head[200002];
int cnt[100004];
int val[100004];
int last=0;
vector<edge> edgelist;
void addedge(int f,int t)
{
    edge x(f,t,head[f]);
    head[f]=last++;
    edgelist.push_back(x);
}
int main()
{
    memset(head,-1,sizeof head);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        addedge(a,b);
        addedge(b,a);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    set<int> Forb;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(cnt[i]==val[i]){
            ans.push_back(i);
            Forb.insert(i);
        }
    }
    while(Forb.size()){
        int cur=*(Forb.begin());
        Forb.erase(Forb.begin());
        for(int i=head[cur];i!=-1;i=edgelist[i].nxt){
            cnt[edgelist[i].t]++;
            if(cnt[edgelist[i].t]==val[edgelist[i].t]){
                ans.push_back(edgelist[i].t);
                Forb.insert(edgelist[i].t);
            }
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
    }
    return 0;
}
