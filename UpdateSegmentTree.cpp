#include <iostream>
using namespace std;


//Information for range [left,right] is present in segTree[pos]
void updateSegmentTree(int segTree[],int updateLeft, int updateRight, int left , int right, int updateValue, int pos)
{	
	//out of bounds
	if (left>right)
		return;
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
		segTree[2*pos+1] += updateValue;
		segTree[2*pos+2] += updateValue;
		return;
	}
	//if partial overlap 
	//carrying the same process of the children
	int mid= (left+right)/2;
	updateSegmentTree(segTree,updateLeft,updateRight,left,mid,updateValue,2*pos+1);
	updateSegmentTree(segTree,updateLeft,updateRight,mid+1,right,updateValue,2*pos+2);
	// using the updated children to determine the value for the parent
	segTree[pos]= min(segTree[2*pos+1],segTree[2*pos+2]);
}
