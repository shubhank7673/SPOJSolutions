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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n;
	cin>>n;
	deque<long long int>a(n);
	long long int i,j,sum=0;
	for(i=0;i<n;i++)cin>>a[i];
    n=a.size();
    long long int sqrt_n=400;
    long long int dec[600]={0};
    sum=0;
    for(i=0,j=-1;i<n;i++)
    {
      if(i%sqrt_n==0)
      {
             j++;
      }
      dec[j]+=a[i];
    }
    long long int q;
    cin>>q;
    while(q--)
    {
    int ch;
    cin>>ch;
    if(ch==1)
    {
    long long int l,r;
    cin>>l>>r;
    l--;r--;
    sum=0;
  	while(l<r&&l%sqrt_n!=0&&l!=0)
	{
    sum+=a[l];
		l++;
	}
	while(l+sqrt_n<=r)
	{
		sum+=dec[l/sqrt_n];
		l+=sqrt_n;
	}
	while(l<=r)
	{
	 sum+=a[l];
	 l++;
	}
	cout<<sum<<endl;
  }
  else
  {
     long long int x,k=1,l_b;
     cin>>x;
     a.push_front(x); 
     n=a.size();
     l_b=(n-1)/400;
     sqrt_n=400;
     sum=0;
     for(i=0;i<l_b;i++)
     {
      dec[i]=dec[i]+x;
      x=a[400*k];
      k++;
      dec[i]-=x;
     }
     dec[l_b]+=x;
  }}
return 0;
} 
