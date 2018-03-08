#include <iostream>

using namespace std;
#define inf 99
#define dim 7
int arr[dim][dim]=
{
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
    int z[dim][3];
    int s,d, min,rmin;
    int r,c;
    for(c=0; c<dim; c++)
        cout<<"\t"<<c;
    cout<<endl;
    for(r=0; r<dim; r++)
    {
        cout<<"\n"<<r<<"\t";
        for(c=0; c<dim; c++)
            if(arr[r][c]==inf)
                cout<<"#\t";
            else
                cout<<arr[r][c]<<"\t";
        cout<<endl;

    }
    cout<<"enter the source";
    cin>>s;
    cout<<"enter the destination want to go it with shortest way";
    cin>>d;


    for(r=0 ; r<dim ; r++)
    {
        z[r][0]=-1;
        z[r][1]=inf;
        z[r][2]=0;

    }
    //first time
    rmin=s;
    min=arr[rmin][rmin];
    z[rmin][0]=s;
    z[rmin][1]=0;
    z[rmin][2]=1;
    //changes the cost between new node enter the z array  (rmin) and all rest nodes (r)
    //but in do loop because when find another nod enter the array ,and when change z[r][2]=1,
    //ويغير بقا cost  يطلع تاني فوق
    do
    {
        for (r=0; r<dim; r++)
        {
            if((z[r][1]>min+ arr[rmin][r])&& (z[r][2]==0) )
            {
                z[r][1]=min+ arr[rmin][r];
                //change the node بمعني خليته يتعزم من خلاله
                z[r][0]=rmin;

            }
        }
        min=inf;
        rmin=-1;
        for(r=0; r<dim; r++)
            if((z[r][2]==0) && (z[r][1]<min))
            {
                min=z[r][1];
                //assign in rmin node ألي هي واقف عنها r
                rmin=r;
            }
        z[rmin][2]=1;
        //print each level
        cout << "rmin= " << rmin << "\t min = " << min << endl;
        for (r = 0; r < dim; r++)
            cout << "\t" << r << "\t" << z[r][0] << "\t" << z[r][1] << "\t" << z[r][2] <<endl;
    }
    while(rmin!=d);
    //print path
    cout<<"the final path is \n ";
    r=d;
    cout<<r<<"\t";
    while(r!=s)
    {
        r=z[r][0];
        cout<<r<<"\t";
    }






}


