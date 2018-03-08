#include <iostream>

using namespace std;
#define dim 7
#define inf 99
int arr[dim][dim]=
{
    { 0, 3, inf, inf, inf, inf, 2 },
    { 3, 0, 2, inf, inf, inf, 5 },
    { inf, 2, 0, 7, 1, 1, 3 },
    { inf, inf, 7, 0, 6, 7, inf },
    { inf, inf, 1, 6, 0, 4, inf },
    { inf, inf, 1, 7, 4, 0, 8 },
    { 2, 5, 3, inf, inf, 8, 0 }

};
void printMatrix(int arr[dim][dim])
{
    int r,c;
    for(c=0; c<dim; c++)
        cout<<"\t"<<c;
    cout<<"\n";
    for(r=0; r<dim; r++)
    {
        cout<<"\n"<<r<<"\t";
        for(c=0; c<dim; c++)
        {
            if(arr[r][c]==inf)
                cout<<"# \t";
            else
                cout<<arr[r][c]<<"\t";
        }
    }
    cout << "\n";
}
int main()
{
    printMatrix(arr);
    printMatrix(arr);
    int r,min,c,rmin,cmin,mstree[dim][dim];
    int z[dim];
    for(r=0; r<dim; r++)
        z[r]=-1;

    for (r = 0; r < dim; r++)
        for (c = 0; c < dim; c++)
            if (r == c) mstree[r][c] = 0;
            else mstree[r][c] = inf;
    int group=0;
    int total_cost=0;

    while(true)
    {
        min=inf;
        /**find min in arr*/
        for (r = 0; r < dim; r++)
            for (c = 0; c < dim; c++)
                if(arr[r][c]<min)
                {
                    rmin=r;
                    cmin=c;
                    min=arr[r][c];
                }
        if(min==inf)
        {
            cout<<"the total min weight is :"<<total_cost<<endl;
            printMatrix(mstree);
            break;
        }
        /**when take min and put it in group*/
        if((z[rmin]==-1)||(z[cmin]==-1)||(z[rmin]!=z[cmin]))
        {
            mstree[rmin][cmin]=mstree[cmin][rmin]=min;
            total_cost+=min;
            /**know situuation of min*/
            if((z[rmin]==-1)&&(z[cmin]==-1))
            {
                group++;
                z[rmin]=z[cmin]=group;
            }
            else if((z[rmin]==-1)&&(z[cmin]=!-1))
                z[rmin]=z[cmin];
            else if((z[rmin]!=-1)&&(z[cmin]==-1))
                z[cmin] =z[rmin];
            else
            {
                int temp=z[cmin];
                for(int i=0; i<dim; i++)
                    if(z[i]==temp)
                        z[i]=z[rmin];
            }

        }
        arr[rmin][cmin]=inf;
    }
    }

}
