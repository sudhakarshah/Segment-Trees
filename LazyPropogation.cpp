#include <iostream>
using namespace std;
// creating a variable with large value
int MAX=999999;

void updateLazyPropogation(int segTree[],int lazyTree[], int updateLeft, int updateRight, int left, int right, int updateValue, int pos)
{
	//out of bounds
	if (left>right)
		return;

	// updating pos with previous operations if not done
	if (lazyTree[pos]!=0)
	{
		segTree[pos] +=lazyTree[pos];
		//if not a leaf node i.e child exists
		if (left!=right)
		{
			lazyTree[2*pos+1] +=lazyTree[pos];
			lazyTree[2*pos+2] +=lazyTree[pos];	
		}
		lazyTree[pos]=0;
	}

	// if there is no overlap
	if (updateRight< left || updateLeft>right)
		return;

	// if only one element i.e the leaf node then update it
	if (left==right)
	{
		segTree[pos] += updateValue;
		return;
	}

	//if full overlap
	if (updateLeft<=left && right<=updateRight)
	{
		segTree[pos] += updateValue;
		lazyTree[2*pos+1] += updateValue;
		lazyTree[2*pos+2] += updateValue;
		return;
	}

	//if partial overlap 
	//carrying the same process of the children
	int mid= (left+right)/2;
	updateLazyPropogation(segTree,lazyTree,updateLeft,updateRight,left,mid,updateValue,2*pos+1);
	updateLazyPropogation(segTree,lazyTree,updateLeft,updateRight,mid+1,right,updateValue,2*pos+2);
	// using the updated children to determine the value for the parent
	segTree[pos]= min(segTree[2*pos+1],segTree[2*pos+2]);

}

int lazyMinimumQuery(int segTree[],int lazyTree[],int queryLeft, int queryRight , int left , int right, int pos)
{

	//out of bounds
	if (left>right)
		return MAX;
	// updating pos with previous operations if not done
	if (lazyTree[pos]!=0)
	{
		segTree[pos] +=lazyTree[pos];
		//if not a leaf node i.e child exists
		if (left!=right)
		{
			lazyTree[2*pos+1] +=lazyTree[pos];
			lazyTree[2*pos+2] +=lazyTree[pos];	
		}
		lazyTree[pos]=0;
	}
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
	return min(lazyMinimumQuery(segTree,lazyTree,queryLeft,queryRight,left,mid,2*pos+1),lazyMinimumQuery(segTree,lazyTree,queryLeft,queryRight,mid+1,right,2*pos+2));
}

