#include <iostream>
using namespace std;

//Information for range [start,end] is present in segTree[pos]
void updateSegmentTree(int segTree[],int updatePos, int start , int end, int updateValue, int pos)
{	
	//out of bounds
	if (start > end)
		return;
	// if there is no overlap
	if (updatePos < start || updatePos > end)
		return;
	// if only one element i.e the leaf node then update it
	if (start == end)
	{
		segTree[pos] = updateValue;
		return;
	}
	
	//if partial overlap 
	//carrying the same process of the children
	int mid= (start+end)/2;
	updateSegmentTree(segTree,updatePos,start,mid,updateValue,2*pos+1);
	updateSegmentTree(segTree,updatePos,mid+1,end,updateValue,2*pos+2);
  
	// using the updated children to determine the value for the parent
	segTree[pos]= min(segTree[2*pos+1],segTree[2*pos+2]);
}
