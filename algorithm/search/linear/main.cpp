#include <iostream>

using namespace std;
int arr[] = {6,4,8,9,3};
int seqsearch(int item)
{
    int loc;
    bool found=false;
    for( loc=0; loc<5; loc++)
        if(arr[loc]==item)
        {
         found=true;
         return loc;
        }
    return -1;
}

int main()
{
    int item;
    while(true)
    {
        cin>>item;
        cout<<seqsearch(item)<<endl;
    }
}


