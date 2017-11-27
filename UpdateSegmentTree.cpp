#include <iostream>
using namespace std;

void updateSegmentTree(int segTree[],int updateLow, int updateHigh, int inputLow , int inputHigh, int updateValue, int pos)
{	
	// if there is no overlap
	if (updateHigh< inputLow || updateLow>inputHigh || inputLow>inputHigh)
		return;

	// if only one element i.e the leaf node then update it
	if (inputLow==inputHigh)
	{
		segTree[pos] += updateValue;
		return;
	}

	//carrying the same process of the children
	int mid= (inputLow+inputHigh)/2;
	updateSegmentTree(segTree,updateLow,updateHigh,inputLow,mid,updateValue,2*pos+1);
	updateSegmentTree(segTree,updateLow,updateHigh,mid+1,inputHigh,updateValue,2*pos+2);

	// using the updated children to determine the value for the parent
	segTree[pos]= min(segTree[2*pos+1],segTree[2*pos+2]);

}


int main()
{
	int test[]={-1,2,-1,2,3,-1,4};

	updateSegmentTree(test,1,2,0,3,2,0);

	for(int i=0;i<7;i++)
	{
		cout<<test[i]<<endl;
	}

}