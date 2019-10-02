#include<bits/stdc++.h>
using namespace std;

// Shubhank Khare

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

int main(void) {
	long long int n,nt=0,total=0,div=5;
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
	nt=0;
	total=0;
	div=5;
	scanf("%lld",&n);
	while(div<=n)
	{
		total=total+n/div;
		div=div*5;
	}
	printf("%lld\n",total);
	}
	return 0;
} 
