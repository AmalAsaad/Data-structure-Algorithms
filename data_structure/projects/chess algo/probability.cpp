#include <iostream>
#include <math.h>
#define inf 99.0

using namespace std;
/*** In this program the user will be entering the
number of customers and their x , y coordinates
which represent the location..
& the program should automatically calculate the
distance between each customer and all the cars
to find the minimum distance...
 ***/
struct location {
 double x;
 double y;
};
struct ST{
    int taxiNum;
    int customerNum;
    double distance;
};

int main(){
	//1) determine number of customers ;
	int numberOfCustomers, numberOfCars;
	struct location* ptrToCust;
	struct location* ptrToCar;
	cout<<"please enter the number of customers : ";
	cin>>numberOfCustomers;
	numberOfCars = numberOfCustomers;
	//Create the array
	ptrToCust = new struct location[numberOfCustomers];
	ptrToCar = new struct location[numberOfCars];
	double **distance;
	distance = new double*[numberOfCustomers];
	for(int i=0 ; i<numberOfCars; i++)
    {
        distance[i] = new double[numberOfCars];
	}
	//2)Take the location of each customer
	for(int i = 0 ; i < numberOfCustomers ; i ++)
	{
		cout<<"the location of customer "<<i+1<<" is :- \n";
		cout<<" x : ";
		cin>>ptrToCust[i].x;
		cout<<" y : ";
		cin>>ptrToCust[i].y;

    }

	//3)Take the location of each car
    for(int i = 0 ; i < numberOfCars ; i++ )
    {
        cout<<"the location of taxi : " <<i+1<<" is :- \n";;
        cout<<" x : ";
        cin>>ptrToCar[i].x;
        cout<<" y : ";
        cin>>ptrToCar[i].y;
    }

	/*4)create the matrix which will tell the distance between each customer and all cars..

	 		     car1 car2 car3 ..
	 customer1
	 customer2
	 customer3
	 .
	 .
	*/

	for (int i = 0; i <numberOfCustomers ; i++)
	{
		for (int j = 0; j < numberOfCars; j++)
		{
			distance[i][j] = sqrt(pow((ptrToCust[i].x - ptrToCar[j].x) ,2) + pow((ptrToCust[i].y - ptrToCar[j].y),2));
		}
	}

	// we will assume that the first probabil
	// double min = a[0][0]+a[1][(1)%3]+a[2][(2)%3];
	//next ,Define the array that will tell you each customer will take which car..

	int *ptr;
	ptr = new int[numberOfCustomers];

	struct ST *storeMin;
	storeMin = new struct ST[numberOfCustomers];

	struct ST *copy;
	copy = new struct ST[numberOfCustomers];
	double min = inf;

	for(int i=0; i<numberOfCustomers; i++)
    {
        for (int counter = 0 ; counter < numberOfCars ; counter++)
            ptr[counter] = -1 ;
        int k = i;
        do{
            int p;
            double minDist = inf;
            for (int y = 0; y < numberOfCars; y++)
            {
                if(distance[k][y] < minDist && ptr[y] == -1 )
                {
                    minDist = distance[k][y];
                    storeMin[k].customerNum = k;
                    storeMin[k].taxiNum = y;
                    storeMin[k].distance = distance[k][y];
                    p = y;
                }
            }
            ptr[p] = 1;
            k++;
            if(k == numberOfCustomers )
                k = 0;
        }while(k != i);

        double result = 0.0;
        for (int l = 0 ; l < numberOfCustomers ; l++)
        {
            result += storeMin[l].distance;
        }

        if (result < min)
        {
            min = result;
            for (int l = 0; l < numberOfCustomers; l++)
            {
                    copy[l].customerNum = storeMin[l].customerNum ;
                    copy[l].taxiNum = storeMin[l].taxiNum ;
                    copy[l].distance = storeMin[l].distance ;
            }
        }
	}

	for (int l = 0; l < numberOfCustomers; l++)
	{
		cout << "Customer : " <<copy[l].customerNum+1<<" will take taxi : "<< copy[l].taxiNum+1<<endl;
	}
    cout<<"Total distance = " << min <<endl;

 	return 0;
}
