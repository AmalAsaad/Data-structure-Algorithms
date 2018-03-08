#include <iostream>

using namespace std;


int linear(int key,int arr[])
{
    int loc;
    bool found=false;
    for(loc=0; loc<6; loc++)
    {
        if(arr[loc]==key)
        {
            found=true;
            return loc;
        }
    }
    return -1;
}

int main()
{
    int arr[]= {2,10,5,6,9,3};
    for(int i=0; i<6; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
    int key;
    while(1)
    {
        cout<<"enter the key"<<endl;
        cin>>key;
        cout<<"the key in the loc : "<<linear(key,arr)<<endl;

    }


}
