#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[4]={},vis[4]={},fh[4]={},a1[4]={},a2[4]={},f=0;
void check(){
  for(int i=0;i<4;i++)
    if(a[i]==24) {f=1;break;}
  if(f==1){
    for(int i=0;i<3;i++){
      cout<<a1[i];
      if(fh[i]==1) cout<<"+"<<a2[i]<<"="<<a1[i]+a2[i]<<endl;
      if(fh[i]==2) cout<<"-"<<a2[i]<<"="<<a1[i]-a2[i]<<endl;
      if(fh[i]==3) cout<<"*"<<a2[i]<<"="<<a1[i]*a2[i]<<endl;
      if(fh[i]==4) cout<<"/"<<a2[i]<<"="<<a1[i]/a2[i]<<endl;
    }
    exit(0);
  }
}
void dfs(int t){
  if(t==1) {check();return;}
  if(t>1)
    for(int i=0;i<4;i++)
      if(a[i]==24) return;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      if(vis[j]==0&&a[i]>=a[j]&&i!=j){
        a1[4-t]=a[i];
        a2[4-t]=a[j];
    a[i]=a[i]+a[j];
        vis[j]=1;
        fh[4-t]=1;
        if(a[i]>0&&vis[i]==0) dfs(t-1);
        vis[j]=0;
        a[i]-=a[j];
        a1[4-t]=a[i];
        a2[4-t]=a[j];
        a[i]=a[i]-a[j];
        vis[j]=1;
        fh[4-t]=2;
        if(a[i]>0&&vis[i]==0) dfs(t-1);
        vis[j]=0;
        a[i]+=a[j];
        a1[4-t]=a[i];
        a2[4-t]=a[j];
        a[i]=a[i]*a[j];
        vis[j]=1;
        fh[4-t]=3;
        if(a[i]>0&&vis[i]==0) dfs(t-1);
        vis[j]=0;
        a[i]/=a[j];
        if(a[i]%a[j]==0){
          a1[4-t]=a[i];
          a2[4-t]=a[j];
          a[i]=a[i]/a[j];
          vis[j]=1;
          fh[4-t]=4;
          if(a[i]>0&&vis[i]==0) dfs(t-1);
          vis[j]=0;
          a[i]*=a[j];
        }
      }
}
int main(){
  int i,j,k;
  for(i=0;i<4;i++)
    cin>>a[i];
  dfs(4);
  if(f==0) cout<<"No answer!"<<endl;
  return 0;
}
