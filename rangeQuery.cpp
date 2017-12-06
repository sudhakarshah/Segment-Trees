#include <iostream>
#include <limits.h>
using namespace std;

// creating a variable with large value, the maximum an integer can hold
int MAX=INT_MAX;

//Minimum for range [start,end] is present in segTree[pos], computed while creating the tree
int minimumQuery(int segTree[], int queryStart, int queryEnd , int start , int end, int pos)
{
	//if there is a full overlap 
	if (queryStart <= start && queryEnd >= end)
	{
		return segTree[pos];
	}
	//if there is no overlap
	else if (queryEnd < start || queryStart > end)
	{
		// returning a very large value
		return MAX;
	}
	//if there is partial overlap
	int mid= (start+end)/2;
	return min(minimumQuery(segTree,queryStart,queryEnd,start,mid,2*pos+1),
		minimumQuery(segTree,queryStart,queryEnd,mid+1,end,2*pos+2));
}
