#include <iostream>

using namespace std;
int arr[]= {1,5,8,10,12,20};
int binary_searcH(int key )
{
    int first=0,last=5;
    bool found=false;


    while(first<=last && !found)
    {
        int mid=(first+last)/2;
        if (key>arr[mid])
            first=mid+1;

        else if(key<arr[mid])
            last=mid-1;
        else
        {
            found=true;
            return mid;
        }

    }
    return -1;

}
int main()
{
    while(true)
    {
        int key;
        cout<<"enter the key";
        cin>>key;
        cout<<binary_searcH(key)<<endl;
    }


}
