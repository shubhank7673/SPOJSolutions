#include<bits/stdc++.h>

//Shubhank Khare

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
 
static auto _ = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

using namespace std;
int check(long int a[],long int n,long int min_d,long int c)
{
    long int i,placed=1;
    long int last=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]-last>=min_d)
           {
            placed++;
           last=a[i];
           }
        if(placed==c)
            return 1;
    }
    return 0;
}
int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
    long int n,c;
    cin>>n>>c;
    long int i,a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long int lo=1,hi=a[n-1]-a[0],mid;
    while(hi-lo>1)
    {
       // cout<<lo<<" "<<hi<<endl;
        mid=lo+(hi-lo)/2;
        if(check(a,n,mid,c))
        {
            lo=mid;
            //break;
        }
        else hi=mid;
    }
    cout<<lo<<endl;
    }
}
