
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

unordered_map<long long ,long long>dp;
long long solveIt(long long n)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n])
    {
        return dp[n];
    }
    long long co = max(n,solveIt(n/2)+solveIt(n/3)+solveIt(n/4));
    dp[n] = co;
    return co;
}
int main()
{
    long long x;
    while(scanf("%lld",&x)==1)
    {
        cout<<solveIt(x)<<"\n";
    }
}
