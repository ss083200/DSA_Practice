
#include<iostream>
#include<climits>
using namespace std;
struct shi{
	public:
	int min;
	int max;
};
struct::shi minMax(int array[],int n)
{
    shi p;
    p.max=INT_MIN;
	p.min=INT_MAX;
	for(int i=0;i<n;i++)
	{
	    if(array[i]>p.max)
	    {
	        p.max=array[i];
	    }
	    if(array[i]<p.min)
	    {
	        p.min=array[i];
	    }
	}
    return p;
}
int main() {
	//code
	int n;
	cin>>n;
	int array[1000];
	for(int i=0;i<n;i++)
	{
	    cin>>array[i];
	} 
	struct shi P=minMax(array,n);
	cout<<P.max<<endl;
	cout<<P.min<<endl;
}
