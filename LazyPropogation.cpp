#include <iostream>
using namespace std;
// creating a variable with large value
int MAX=999999;

void updateLazyPropogation(int segTree[],int lazyTree[], int updateLow, int updateHigh, int inputLow, int inputHigh, int updateValue, int pos)
{
	//out of bounds
	if (inputLow>inputHigh)
		return;

	// updating pos with previous operations if not done
	if (lazyTree[pos]!=0)
	{
		segTree[pos] +=lazyTree[pos];
		//if not a leaf node i.e child exists
		if (inputLow!=inputHigh)
		{
			lazyTree[2*pos+1] +=lazyTree[pos];
			lazyTree[2*pos+2] +=lazyTree[pos];	
		}
		lazyTree[pos]=0;
	}

	// if there is no overlap
	if (updateHigh< inputLow || updateLow>inputHigh)
		return;

	// if only one element i.e the leaf node then update it
	if (inputLow==inputHigh)
	{
		segTree[pos] += updateValue;
		return;
	}

	//if full overlap
	if (updateLow<=inputLow && inputHigh<=updateHigh)
	{
		segTree[pos] += updateValue;
		lazyTree[2*pos+1] += updateValue;
		lazyTree[2*pos+2] += updateValue;
		return;
	}

	//if partial overlap 
	//carrying the same process of the children
	int mid= (inputLow+inputHigh)/2;
	updateLazyPropogation(segTree,lazyTree,updateLow,updateHigh,inputLow,mid,updateValue,2*pos+1);
	updateLazyPropogation(segTree,lazyTree,updateLow,updateHigh,mid+1,inputHigh,updateValue,2*pos+2);

	// using the updated children to determine the value for the parent
	segTree[pos]= min(segTree[2*pos+1],segTree[2*pos+2]);

}


int lazyMinimumQuery(int segTree[],int lazyTree[],int queryLow, int queryHigh , int inputLow , int inputHigh, int pos)
{

	//out of bounds
	if (inputLow>inputHigh)
		return MAX;


	// updating pos with previous operations if not done
	if (lazyTree[pos]!=0)
	{
		segTree[pos] +=lazyTree[pos];
		//if not a leaf node i.e child exists
		if (inputLow!=inputHigh)
		{
			lazyTree[2*pos+1] +=lazyTree[pos];
			lazyTree[2*pos+2] +=lazyTree[pos];	
		}
		lazyTree[pos]=0;
	}

	//if there is a full overlap 
	if (queryLow<= inputLow && queryHigh>=inputHigh)
	{
		return segTree[pos];
	}

	//if there is no overlap
	else if (queryHigh< inputLow || queryLow>inputHigh)
	{
		// returning a very large value
		return MAX;
	}

	//if there is partial overlap
	int mid= (inputLow+inputHigh)/2;

	return min(lazyMinimumQuery(segTree,lazyTree,queryLow,queryHigh,inputLow,mid,2*pos+1),lazyMinimumQuery(segTree,lazyTree,queryLow,queryHigh,mid+1,inputHigh,2*pos+2));
}


int main()
{
	int test[]={-1,2,-1,2,3,-1,4};
	int lazy[]={0,0,0,0,0,0,0};

	updateLazyPropogation(test,lazy,0,3,0,3,2,0);
	cout<<lazyMinimumQuery(test,lazy,0,1,0,3,0)<<endl;
	updateLazyPropogation(test,lazy,2,2,0,3,4,0);
	cout<<lazyMinimumQuery(test,lazy,1,2,0,3,0);

}
