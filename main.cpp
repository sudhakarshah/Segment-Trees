#include "createTree.cpp"
#include "rangeUpdateSegmentTree.cpp"
#include "rangeQuery.cpp"
#include <iostream>
#include <cmath>
using namespace std;
#include <limits.h>
// creating a variable with large value
int MAX=INT_MAX;



int main()
{
	//n is size of input array. q is total number of queries
	int n,q;
	cin>>n;
	int* arr;
	arr=new int[n];

	//taking user input of array elemts
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin >> q;
	int* segTree;
	int height = ceil(log(n)/log(2));
	int length = 2*(int)pow(2,height)-1;
	segTree=new int[length];

	// initializing the segment tree array with a very large number
	for(int i=0;i<length;i++)
	{
		segTree[i] = MAX;
	}
	createTree(arr,segTree,0,n-1,0);
	for (int i=0;i<q;i++)
	{
		int start,end;
		cin>>start>>end;
		cout<<minimumQuery(segTree, start, end , 0 , n-1, 0)<<endl;
	}
}