#include "createTree.cpp"
#include "singleUpdate.cpp"
#include "rangeQuery.cpp"
#include <iostream>
#include <cmath>
using namespace std;
#include <limits.h>
// creating a variable with highest value an integer can hold
int MAX=INT_MAX;

int main()
{
	//n is size of input array. q is total number of queries
	int n,q;
	cin >> n;
	int* arr;
	arr=new int[n];

	//taking user input of array elemts
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cin >> q;
	int* segTree;
	// The height of the segment tree which is a binary tree
	int height = ceil(log(n)/log(2)); 
	// The length of the array holding the segment tree
	int length = 2*(int)pow(2,height)-1;
	segTree=new int[length];

	// initializing the segment tree array with MAX
	for(int i=0;i<length;i++)
	{
		segTree[i] = MAX;
	}
	// Creating the tree
	createTree(arr,segTree,0,n-1,0);

	/* 
	Taking the queries. They can be of 2 types
	1. u 3 -3 
	( u - update; this means we need to update position 3 of the input array to -3)
	2. q 0 4
	( q - query; this means we need to find the minimum value of the input array between positions 0 and 4)
	*/
	for (int i=0;i<q;i++)
	{
		char x;
		cin >> x;
		if(x == 'q')
		{
			int start,end;
			cin >> start >> end;
			cout << minimumQuery(segTree, start, end , 0 , n-1, 0) << endl;
		}
		if(x == 'u')
		{
			int position,value;
			cin >> position >> value;
			updateSegmentTree(segTree, position, 0, n-1, value, 0)
		}
	}
}
