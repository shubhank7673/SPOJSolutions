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

#define long long long
long int x,ind;
struct node
{
    long int a;
    long int b;
}st[5*100000];
node merge(node a1,node b1)
{
    node temp;
    long int ar[4];
    ar[0]=a1.a;
    ar[1]=a1.b;
    ar[2]=b1.a;
    ar[3]=b1.b;
    sort(ar,ar+4);
    temp.a=ar[3];
    temp.b=ar[2];
    return temp;
}
node query(node st[],long int ss,long int se,long int l,long int r,long int si)
{
    //cout<<ss<<" "<<se<<endl;
    if(l>se||r<ss)
    {
        node temp;
        temp.a=temp.b=INT_MIN;
        return temp;
    }
    if(l<=ss&&r>=se)
        return st[si];
    long int mid=(ss+se)/2;
    node a1,b1;
    a1=query(st,ss,mid,l,r,si*2+1);
    b1=query(st,mid+1,se,l,r,si*2+2);
    node ans=merge(a1,b1);
    return ans;
}
void update(long int ss,long int se,long int si)
{
    if(ind<ss||ind>se)
        return;
    if(se==ss)
    {
        st[si].a=x;
        st[si].b=INT_MIN;
        return;
    }
     long int mid=(se+ss)/2;
     update(ss,mid,si*2+1);
     update(mid+1,se,si*2+2);
     st[si]=merge(st[2*si+2],st[2*si+1]);
}
node build(long int l,long int r,long int ar[],long int si)
{
    if(l==r)
    {
        st[si].a=ar[l];
        st[si].b=INT_MIN;
        return st[si];
    }
    long int mid=(l+r)/2;
    node a1,b1;
    a1=build(l,mid,ar,si*2+1);
    b1=build(mid+1,r,ar,si*2+2);
    st[si]=merge(a1,b1);
    return st[si];
}
int main()
{
    long int n;
    cin>>n;
    long int a[n];
    long int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    build(0,n-1,a,0);
    long int q;
    cin>>q;
    while(q--)
    {
    char ch;
    cin>>ch;
    if(ch=='Q')
    {long int l,r;
    cin>>l>>r;
    l--,r--;
    node ans;
    ans=query(st,0,n-1,l,r,0);
    cout<<(ans.a+ans.b)<<endl;
    }
    else if(ch=='U')
    {
    cin>>ind>>x;
    --ind;
    update(0,n-1,0);
    /*for(long int i=0;i<9;i++)
    {
        cout<<st[i].a<<" "<<st[i].b<<endl;
    }*/
    }
    }
}
 
