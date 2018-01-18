#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > adjlist;
bool ondim[100005];
int nd2;
pair<int,int> mxLenNNode(int node,int parent)
{
    pair<int,int> ret=make_pair(0,node);
    for(int i=0;i<adjlist[node].size();i++){
        if(adjlist[node][i]!=parent){
            pair<int,int> tmp=mxLenNNode(adjlist[node][i],node);
            tmp.first++;
            ret=max(ret,tmp);
        }
    }
    return ret;
}
bool get_path(int node,int parent)
{
    if(node==nd2)
        return ondim[node]=1;
    bool ret=0;
    for(int i=0;i<adjlist[node].size();i++){
        if(adjlist[node][i]!=parent){
            ret|=get_path(adjlist[node][i],node);
        }
    }
    ondim[node]=ret;
    return ret;
}
vector<int> path;
void construct_path(int node,int parent)
{
    int pthnode=-1;
    path.push_back(node);
    for(int i=0;i<adjlist[node].size();i++){
        if(adjlist[node][i]!=parent&&!ondim[adjlist[node][i]]){
            construct_path(adjlist[node][i],node);
            path.push_back(node);
        }
        else if(adjlist[node][i]!=parent&&ondim[adjlist[node][i]]){
            pthnode=adjlist[node][i];
        }
    }
    if(pthnode!=-1){
        construct_path(pthnode,node);
    }
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    adjlist.resize(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    pair<int,int> tmp=mxLenNNode(1,1);
    int nd1=tmp.second;
    tmp=mxLenNNode(tmp.second,tmp.second);
    nd2=tmp.second;
    get_path(nd1,nd1);
    printf("%d\n",2*(n-1)-tmp.first);
    construct_path(nd1,nd1);
    for(int i=0;i<path.size();i++){
        printf("%d%c",path[i]," \n"[i==path.size()-1]);
    }
    return 0;
}
