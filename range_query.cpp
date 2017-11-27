#include <iostream>
using namespace std;

// creating a variable with large value
int MAX=999999;

int minimumQuery(int segTree[], int queryLow, int queryHigh , int inputLow , int inputHigh, int pos)
{
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

	return min(minimumQuery(segTree,queryLow,queryHigh,inputLow,mid,2*pos+1),minimumQuery(segTree,queryLow,queryHigh,mid+1,inputHigh,2*pos+2));

}

int main()
{
	int test[]={-1,-1,0,-1,2,4,0};

	cout<<minimumQuery(test,1,3,0,3,0);

}