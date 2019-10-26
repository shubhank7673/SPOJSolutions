#include<bits/stdc++.h>
using namespace std;
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
 
