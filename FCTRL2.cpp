#include<boost/multiprecision/cpp_int.hpp>
#include <iostream>
using namespace boost::multiprecision;
using namespace std;
 
int main() 
{
	cpp_int t;
	cin>>t;
	while(t--)
	{cpp_int f;
	cpp_int n;
            cpp_int i;
	cin>>n;
	f=1;
            for(i=n;i>0;i--)
	{
		f=f*i;
	}
	cout<<f<<endl;
	}
} 
