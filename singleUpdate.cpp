#include <iostream>
using namespace std;

//Information for range [start,end] is present in segTree[pos]
void updateSegmentTree(int segTree[],int updatePos, int start , int end, int updateValue, int pos)
{	
	//out of bounds
	if (start > end)
		return;
	// if the position to be updated is outside the range present in the node
	if (updatePos < start || updatePos > end)
		return;
	// if only one element i.e the leaf node then update it
	if (start == end)
	{
		segTree[pos] = updateValue;
		return;
	}
	//carrying the same process of the children to get to the leaf node holding the posiiton to be updated
	int mid= (start+end)/2;
	updateSegmentTree(segTree,updatePos,start,mid,updateValue,2*pos+1);
	updateSegmentTree(segTree,updatePos,mid+1,end,updateValue,2*pos+2);
  
	// using the updated children to determine the value for the parent
	segTree[pos]= min(segTree[2*pos+1],segTree[2*pos+2]);
}
