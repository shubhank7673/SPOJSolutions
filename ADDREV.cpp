#include<bits/stdc++.h>
using namespace std;

//Shubhank Khare

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

int main() {
long long int t;
scanf("%lld",&t);
while(t--)
{
int n1,n2,rev1=0,rev2=0,rev3=0;
scanf("%d%d",&n1,&n2);
while(n1)
{
	rev1=rev1*10+n1%10;
	n1=n1/10;
}
while(n2)
{
	rev2=rev2*10+n2%10;
	n2=n2/10;
}
rev3=rev1+rev2;
rev1=0;
while(rev3)
{
	rev1=rev1*10+rev3%10;
	rev3/=10;
}
printf("%d\n",rev1);
}
return 0;
}
