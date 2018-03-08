#include <iostream>

using namespace std;
#define inf 99
#define dim 7
int arr[dim][dim]=
{

    { 0, 3, inf, inf, inf, inf, 5 },
    { 3, 0, 2, inf, inf, inf, 5 },
    { inf, 2, 0, 7, 1, 1, 3 },
    { inf, inf, 7, 0, 6, 7, inf },
    { inf, inf, 1, 6, 0, 4, inf },
    { inf, inf, 1, 7, 4, 0, 8 },
    { 5, 5, 3, inf, inf, 8, 0 }
};
int main()
{
    int r,c;
    int total_wight=0;
    int rmin, min,newmin;
    int z[dim][3];
    int spTree[dim][dim];
    for (c = 0; c < dim; c++)
        cout << "\t" << c;
    cout << "\n";
    for (r = 0; r < dim; r++)
    {
        cout << "\n" << r << "\t";
        for (c = 0; c < dim; c++)
            if (arr[r][c] == inf)
                cout << "#\t";
            else
                cout << arr[r][c] << "\t";
    }
    cout << "\n";
    for(r=0; r<dim; r++)
    {
        z[r][0]=-1;
        z[r][1]=inf;
        z[r][2]=0;
    }

    rmin=0;
    min=arr[rmin][rmin];
    z[rmin][0]=0;
    z[rmin][1]=0;
    z[rmin][2]=1;
    do
    {
        for(r=0; r<dim; r++)
        {
            if((z[r][2]==0)&&(z[r][1]>arr[rmin][r]))
            {
                z[r][1]=arr[rmin][r];
                z[r][0]=rmin;

            }
        }
        rmin=-1;
        min=inf;
        newmin = -1;
        for(r=0; r<dim; r++)
            if((z[r][2]==0)&&(z[r][1]<min))
            {
                min=z[r][1];
               // rmin=z[r][0];
                rmin=r;

            }
         if(min==inf)
            break;

        total_wight=total_wight+min;
        cout << "rmin= " << rmin << "\t min = " << min << endl;
         //rmin = newmin;
        for (r = 0; r < dim; r++)
            cout << "\t" << r << "\t" << z[r][0] << "\t" << z[r][1] << "\t" << z[r][2] <<endl;
        z[rmin][2]=1;

    }
    while(rmin!=-1);
    cout<<"minmun total wight  "<<total_wight<<endl;





    }
