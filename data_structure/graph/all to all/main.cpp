#include <iostream>

using namespace std;
#define inf 99
#define dim 7
int arr[dim][dim]={
{ 0, 1, inf, inf, inf, 2, inf },
{ 1, 0, 8, inf, inf, inf, inf },
{ inf, 8, 0, 4, inf, 3, inf },
{ inf, inf, 4, 0, 6, inf, inf },
{ inf, inf, inf, 6, 0, 5, inf },
{ 2, inf, 3, inf, 5, 0, 2 },
{ inf, inf, inf, inf, inf, 2, 0 }
};

int main()
{
    int s,d ,via ,counter;
    int r,c;
    for(r=0; r<dim; r++)
    {
        for(c=0; c<dim; c++)
        {
            if(arr[r][c]==inf)
               cout<<"#"<<"\t";
            else
                cout<<arr[r][c]<<"\t";

        }
        cout<<endl;
    }



    //do
    while(counter>0)
    {
        counter=0;
        for(s=0 ;s<dim ;s++)
            for(d=0 ; d<dim ; d++)
               for(via=0 ; via <dim ;via++)
                 if(arr[s][d]>arr[s][via]+arr[via][d])
                 {
                     arr[s][d]=arr[s][via]+arr[via][d];
                     counter++;
                 }
        cout<<"counter is:"<<counter<<endl;
        for(r=0; r<dim; r++)
        {
           for(c=0; c<dim; c++)
                cout<<arr[r][c]<<"\t";
           cout<<endl;
        }

    }
   //while (counter>0); //if that true ,make the operation in do,still in do don't out
   cout<<"this is all to all shorted path for this graph";


}
