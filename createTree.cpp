//Segment Tree
#include <iostream>
using namespace std;


void createTree(int input[],int segTree[],int left, int right, int pos)
{
    // if only one element is left
    if (right==left)
    {
        segTree[pos]=input[left];
        return;
    }
    int mid=(right+left)/2;
    //creating the left child
    createTree(input,segTree,left,mid,2*pos+1);
    //creating the right child
    createTree(input,segTree,mid+1,right,2*pos+2);
    segTree[pos]= min(segTree[2*pos+1],segTree[2*pos+2]);
}
