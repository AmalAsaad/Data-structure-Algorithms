#include <iostream>
#include <math.h>

using namespace std;

struct node
{
    int x, y;
};

double directDistance(node a, node b)
{
    return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0));
}

bool check(int *arr, int size, int taxi, int customer)
{
    for(int r=0; r<taxi; r++)
        if((arr[r] == customer))
            return false;
    return true;
}

int main()
{
    int n, r;
    cout << " Please Enter the number of customers: " << endl;
    cin >> n;
    int *solution = new int[n];
    int *trySolutions = new int[n];
    struct node *taxi = new struct node[n];
    struct node *customer = new struct node[n];
    int minDist = -1;

    for(int i = 0 ; i < n; i ++)
	{
		cout<<"the location of customer "<<i+1<<" is :- \n";
		cout<<" x : ";
        cin>>customer[i].x;
        cout<<" y : ";
        cin>>customer[i].y;
    }
    for(int i = 0 ; i < n; i++ )
    {
        cout<<"the location of taxi : "<<i+1<<" is :- \n";
        cout<<" x : ";
        cin>>taxi[i].x;
        cout<<" y : ";
        cin>>taxi[i].y;
    }

    for(r=0; r<n; r++)
        solution[r] = trySolutions[r] = -1;

    r = 0;
    while(r != -1)
    {
        if(r == n)
        {
            int dist = 0;
            for(int i=0; i<n; i++)
                dist += directDistance(taxi[i], customer[trySolutions[i]]);
            if(minDist == -1 || dist < minDist)
            {
                minDist = dist;
                for(int i=0; i<n; i++)
                    solution[i] = trySolutions[i];
            }
            r--;
        }
        else if(trySolutions[r]+1 == n)
        {
            trySolutions[r] = -1;
            r--;
        }
        else
        {
            trySolutions[r]++;
            if(check(trySolutions, n, r, trySolutions[r]))
                r++;
        }
    }

    cout << "Solution: \n";

	for (int i = 0; i < n; i++)
	{
		cout << "Customer : " <<solution[i]+1<<" will take taxi : "<< i+1<<endl;
	}
    cout<<"Total distance = " << minDist <<endl;

    delete solution;
    delete trySolutions;
    delete taxi;
    delete customer;
    return 0;
}
