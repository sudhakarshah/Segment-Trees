#include <iostream>
using namespace std;

// creating a variable with large value
int MAX=999999;


//Information for range [left,right] is present in segTree[pos]
int minimumQuery(int segTree[], int queryLeft, int queryRight , int left , int right, int pos)
{
	//if there is a full overlap 
	if (queryLeft<= left && queryRight>=right)
	{
		return segTree[pos];
	}
	//if there is no overlap
	else if (queryRight< left || queryLeft>right)
	{
		// returning a very large value
		return MAX;
	}
	//if there is partial overlap
	int mid= (left+right)/2;
	return min(minimumQuery(segTree,queryLeft,queryRight,left,mid,2*pos+1),minimumQuery(segTree,queryLeft,queryRight,mid+1,right,2*pos+2));

}

