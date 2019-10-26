#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007 
#define VALUEIN
#ifdef VALUEIN
#define valuein(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define valuein(...)
#endif


long int graph[2001][2001]={0};
int colour[2001];
bool is_bip(long int n,long int src)
{
    //int colour[n];
    //for(long int i=0;i<n;i++) colour[i]=-1;
    colour[src]=1;
    queue<long int >q;
    q.push(src);
    while(!q.empty())
    {
        long int u=q.front();
        q.pop();
        if(graph[u][u]==1)
            return false;
        for(long int i=0;i<n;i++)
        {
            if(graph[u][i]&&colour[i]==-1)
            {
                colour[i]=1-colour[u];
                q.push(i);
            }
            else if(graph[u][i]&&colour[u]==colour[i])
                   return false;
        }
    }
    return true;
}
bool check(long int n)
{
    //bool visited[n];
    //memset(visited,false,sizeof(visited));
    for(long i=0;i<n;i++) colour[i]=-1;
    for(long int i=0;i<n;i++)
    {
        if(colour[i]==-1)
           if(!is_bip(n,i))
           {
               return false;
           }
    }
    return true;
}
int main()
{
    long int t;
    cin>>t;
    for(long int tt=1;tt<=t;tt++)
    {
        long int n,m;
        cin>>n>>m;
        memset(graph,0,sizeof(graph));
        while(m--)
        {
            long int i,j;
            cin>>i>>j;
            i--,j--;
            graph[i][j]=1;
            graph[j][i]=1;
        }
        printf("Scenario #%d:\n",tt);
        if(!check(n))
        {
            printf("Suspicious bugs found!\n");
        }
        else
        {
            printf("No suspicious bugs found!\n");
        }
    }
}
 
