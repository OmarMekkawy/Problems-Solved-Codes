#include <bits/stdc++.h>

using namespace std;
#define debug(x) cout<<#x<<"->"<<x<<endl;
double arr[100001];
double segmentTree[400005];
double lazy1[400001],lazy2[400001];
void Build(int st,int ed,int idx)
{
    if(st==ed){
        segmentTree[idx]=arr[st];
        return;
    }
    Build(st,(st+ed)>>1,idx*2);
    Build(((st+ed)>>1)+1,ed,idx*2+1);
    segmentTree[idx]=segmentTree[idx*2]+segmentTree[idx*2+1];
    return;
}
void lazy(int st,int ed,int idx,double mul=1,double add=0)
{
    lazy2[idx]*=mul;
    lazy2[idx]+=(1.0-mul)*add;
    segmentTree[idx]=segmentTree[idx]*mul*lazy1[idx]+lazy2[idx]*(1.0+ed-st);
    if(st!=ed){
        lazy1[idx*2]*=lazy1[idx]*mul;
        lazy2[idx*2]*=lazy1[idx]*mul;
        lazy2[idx*2]+=lazy2[idx];
        lazy1[idx*2+1]*=lazy1[idx]*mul;
        lazy2[idx*2+1]*=lazy1[idx]*mul;
        lazy2[idx*2+1]+=lazy2[idx];
    }
    lazy1[idx]=1;
    lazy2[idx]=0;
    return;

}
double Query(int st,int ed,int idx,int &qst,int &qed)
{
    lazy(st,ed,idx);
    if(st>=qst&&ed<=qed)
        return segmentTree[idx];
    if(st>qed||ed<qst)
        return 0;
    return Query(st,(st+ed)>>1,idx*2,qst,qed)+Query(((st+ed)>>1)+1,ed,idx*2+1,qst,qed);
}
void Update(int st,int ed,int idx,int &ust,int &ued,double val,double prob)
{
    lazy(st,ed,idx);
    if(ued<st||ust>ed)
        return;
    if(st>=ust&&ed<=ued){
        lazy(st,ed,idx,prob,val);
        return ;
    }
    Update(st,(st+ed)>>1,idx*2,ust,ued,val,prob);
    Update(((st+ed)>>1)+1,ed,idx*2+1,ust,ued,val,prob);
    segmentTree[idx]=segmentTree[idx*2]+segmentTree[idx*2+1];
    return;
}
int main()
{
    for(int i=0;i<400001;i++)
        lazy1[i]=1;
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lf",&arr[i]);
    Build(1,n,1);
    while(q--){
        int type;
        scanf("%d",&type);
        if(type==1){
            int l1,r1,l2,r2;
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            double cursum=(double)Query(1,n,1,l1,r1)/(double)(r1-l1+1);
            double cursum2=(double)Query(1,n,1,l2,r2)/(double)(r2-l2+1);
            Update(1,n,1,l1,r1,cursum2,1.0-1.0/(r1-l1+1.0));
            Update(1,n,1,l2,r2,cursum,1.0-1.0/(r2-l2+1.0));
        }
        else{
            int l1,r1;
            scanf("%d%d",&l1,&r1);
            printf("%.8f\n",Query(1,n,1,l1,r1));
        }
    }
    return 0;
}
