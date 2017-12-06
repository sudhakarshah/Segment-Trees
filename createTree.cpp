//Segment Tree
#include <iostream>
using namespace std;


void createTree(int input[],int segTree[],int start, int end, int pos)
{
    // if only one element is left
    if (start==end)
    {
        segTree[pos]=input[start];
        return;
    }
    int mid=(start+end)/2;
    //creating the left child
    createTree(input,segTree,start,mid,2*pos+1);
    //creating the right child
    createTree(input,segTree,mid+1,end,2*pos+2);
    segTree[pos]= min(segTree[2*pos+1],segTree[2*pos+2]);
}
