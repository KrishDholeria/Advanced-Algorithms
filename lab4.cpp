#include <iostream>
using namespace std;
#define N 4
int G[N][N]={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
int G1[N][N];

int count_edges()
{
    int counter=0;
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(G[i][j]==1)
               counter++;
        }
    }
    return counter;
}
void create_edge_matrix(int E[][2])
{
    int i,j;int x=0;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(G[i][j]==1)
            {
               E[x][0]=i;
               E[x][1]=j;
               x++;
            }
        }
    }
    
}
int find(int node,int parent[])
{
        if(node==parent[node]) return node;
        
        return parent[node]=find(parent[node],parent);
}
void Union(int u,int v,int parent[])
{
        u=find(u,parent);
        v=find(v,parent);
        parent[v]=u;
}
    
int main() 
{
    std::cout << "Hello world!";
    srand(time(NULL));
    int parent[N]={0,1,2,3};
    int m=count_edges();
    cout<<"Number of Edges"<<m<<endl;   
    int i,j;int n=N;
    int edges[m][2];
    create_edge_matrix(edges);
 while(n>2)
 {
    int u,v;
    int e=rand()%m;
    u=edges[e][0];
    v=edges[e][1];
    
    int set1=find(u,parent);
    int set2=find(v,parent);
            
    if(set1!=set2)
    {
                cout<<"Contracting vertices "<<u<<" and "<<v<<endl;
                Union(u,v,parent);
                n--;
    }
 }       
    cout<<"Edges needs to be removed - "<<endl;
    int ans=0;
    for(i=0;i<N;i++)
      cout<<parent[i]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++)
    {
            int set1=find(edges[i][0],parent);
            int set2=find(edges[i][1],parent);
            
            if(set1!=set2)
            {
                cout<<edges[i][0]<<" <----> "<<edges[i][1]<<endl;
                ans++;
            }
    }
    cout<<ans<<endl;
    return 0;
}