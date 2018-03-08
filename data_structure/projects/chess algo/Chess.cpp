#include <iostream>

//Comment the next line if you want only a single solution.
#define SHOW_ALL_SOLUTIONS

using namespace std;

int absoluteDifference(int a, int b)  //Calculates the Absolute difference between 2 numbers.
{
    if(a>b)
        return a-b;
    else
        return b-a;
}

bool check(int *arr, int size, int row, int col) //Check that the queen in this row, col can't eat any other queens in the previous rows.
{
    for(int r=0; r<row; r++)
        if((arr[r] == col) || (absoluteDifference(arr[r], col) == absoluteDifference(r, row)))
            return false;
    return true;
}

void print(int *arr, int size)
{
    cout<<endl;
    for(int r=0; r<size; r++)
    {
        for(int c=0; c<size; c++)
        {
            if(c == arr[r])
                cout<<"Q ";
            else
                cout<<"# ";
        }
        cout << endl;
    }
    cout<<endl;
}

int main()
{
    //The size of the board is n*n
    //r will represent the row number
    //r will take values from 0 to n-1
    //arr[r] will represent which column is selected to put the queen in it for a particular row (r).
    //arr[r] will take values from 0 to n-1
    //arr[r] will take value of -1 to indicate that the queen is outside the board for this particular row (r).

    int n, r;
    cout << " Please Enter the board size: " << endl;
    cin >> n;
    int *arr = new int(n);
    for(r=0; r<n; r++)
        arr[r] = -1;    //Assume all queens are initially outside the board

#ifdef SHOW_ALL_SOLUTIONS
    cout << "All Possible Solutions: \n";
#endif // SHOW_ALL_SOLUTIONS

    r = 0;  //Start with the 1st row.
    while(r != n)
    {
        if(r == -1) //If there is no more solutions
            break;
        else if(arr[r]+1 == n) //If all columns don't fit
        {
            arr[r] = -1; //set column to -1
            r--;         //move back to the previous row
        }
        else
        {
            arr[r]++;                //move to the next column.
            if(check(arr, n, r, arr[r])) //If it fits.
                r++;                     //move to the next row.
        }

#ifdef SHOW_ALL_SOLUTIONS
        if(r == n)  //if Solution found.
        {
            print(arr, n);  //print solution.
            r--;            //try another solution.
        }
#endif // SHOW_ALL_SOLUTIONS

    }

#ifndef SHOW_ALL_SOLUTIONS
    if(r == -1)
        cout << "There is no possible solution.";
    else
    {
        cout << "Solution: \n";
        print(arr, n);  //print solution.
    }
#endif // SHOW_ALL_SOLUTIONS

    delete arr;
    return 0;
}
