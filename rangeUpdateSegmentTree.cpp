#include <iostream>
using namespace std;


//Information for range [start,end] is present in segTree[pos]
void rangeUpdateSegmentTree(int segTree[],int updateStart, int updateEnd, int start , int end, int updateValue, int pos)
{	
	//out of bounds
	if (start>end)
		return;
	// if there is no overlap
	if (updateEnd< start || updateStart>end)
		return;
	// if only one element i.e the leaf node then update it
	if (start==end)
	{
		segTree[pos] = segTree[pos] & updateValue;
		return;
	}
	//if full overlap
	if (updateStart<=start && end<=updateEnd)
	{
		segTree[pos] = segTree[pos] & updateValue;
		segTree[2*pos+1] = segTree[2*pos+1] & updateValue;
		segTree[2*pos+2] =segTree[2*pos+2] & updateValue;

		/*
		segTree[pos] += updateValue;
		segTree[2*pos+1] += updateValue;
		segTree[2*pos+2] += updateValue;
		*/
		return;
	}
	//if partial overlap 
	//carrying the same process of the children
	int mid= (start+end)/2;
	rangeUpdateSegmentTree(segTree,updateStart,updateEnd,start,mid,updateValue,2*pos+1);
	rangeUpdateSegmentTree(segTree,updateStart,updateEnd,mid+1,end,updateValue,2*pos+2);
	// using the updated children to determine the value for the parent
	segTree[pos]= min(segTree[2*pos+1],segTree[2*pos+2]);
}
