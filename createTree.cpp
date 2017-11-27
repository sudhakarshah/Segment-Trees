//Segment Tree
#include <iostream>
using namespace std;


void createTree(int input[],int segTree[],int low, int high, int pos)
{
    // if only one element is left
    if (high==low)
    {
        segTree[pos]=input[low];
        return;
    }

    int mid=(high+low)/2;

    //creating the left child
    createTree(input,segTree,low,mid,2*pos+1);
    //creating the right child
    createTree(input,segTree,mid+1,high,2*pos+2);

    segTree[pos]= min(segTree[2*pos+1],segTree[2*pos+2]);


}


int main()
{
    int arr[]={-1,2,4,0};
    int segTree[]={10000,1000,1000,1000,10000,1000,1000};
    createTree(arr,segTree,0,3,0);
   
    for (int i=0;i<7;i++)
    {
        cout<<segTree[i]<<endl;
    }

}
