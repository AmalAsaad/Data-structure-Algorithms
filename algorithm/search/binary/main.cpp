
#include <iostream>

using namespace std;

int binary(const int item)
{

 int  list[]={0,1,2,5,6,7};
 int first=0;
 int last = 5;
 bool found= false;
 while(first<=last&&!found)
 {
     int mid =(first+last)/2;
     if(item==list[mid])
     {
         found=true;

     }
     else if(item<list[mid])
     {
         last=mid-1;
     }
     else
     {
         first=mid+1;
     }
 }
 if (found)
    return mid;
 else
    return -1;
}
int main()
{

    int item;
    cout<<"enter the item wanted to found"<<"\t";
    while(true)

    {
          cin>>item;
          cout<<binary(item)<<endl;
    }

}
