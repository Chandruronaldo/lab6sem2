#include <iostream>
using namespace std;

#define MAX 1000 //the maximum number of elements in the array
int binarysearch(int alp[],int bet,int gamma,int del)
{
	int k=(bet+gamma)/2; // Middle element of the alp array
	
	while(bet<=gamma) // comparing the end indices
	{
	//If alp[k] is greater than k, then k lies in the left subarray
	if(alp[k]>del)
	binarysearch(alp,0,k,del);
	//If alp[k] is less than k, then k lies in the right subarray
	else if(alp[k]<del)
	binarysearch(alp,k,gamma,del);
            else if(alp[k]==del)//The equality condition
            return k;//The index of searched elemnt is returned
           
	}

	return -1;// If the func reaches here the del is not presnt in the array, so -1 is returned
	
}

int main() 
{
	int a[MAX],b,c,d;
	cout<<"\n enter the number of elements in the array";
	cin>>b;
	
	//func runs only with sorted array
	cout<<"\n enter the elements of sorted array";
	for(int i=0;i<b;i++)
	{
		cin>>a[i];
	}
	cout<<"\n enter the element to be searched\n";
	cin>>c;
	
	d=binarysearch(a,0,b,c);
	if(d!=-1)
	cout<<"\n The number is present in position "<<d+1<<" the array";
	else
	cout<<"\n The number is absent in position the array";
	return 0;
}