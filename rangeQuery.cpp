#include <iostream>
using namespace std;

// creating a variable with large value
int MAX=999999;


//Information for range [start,end] is present in segTree[pos]
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
	return min(minimumQuery(segTree,queryStart,queryEnd,start,mid,2*pos+1),minimumQuery(segTree,queryStart,queryEnd,mid+1,end,2*pos+2));
}

