#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_SUBJECTS 30
#define NUMBER_STUDENTS 100

using namespace std;

int registeration[NUMBER_STUDENTS][NUMBER_SUBJECTS] = {0};
int conflict[NUMBER_SUBJECTS][NUMBER_SUBJECTS] = {0};
int days[NUMBER_SUBJECTS][NUMBER_SUBJECTS] = {0};

bool isConflict(int s1, int s2)
{
    if(conflict[s1][s2] > 0)
        return true;
    else
        return false;
}

void randomize()
{
    for(int r=0 ; r< NUMBER_STUDENTS ; r++)
    {
        int counter = 0;
        while(counter < 5)
        {
            int n = rand() % NUMBER_SUBJECTS;
            if(registeration[r][n] == 0)
            {
                registeration[r][n] = 1;
                counter++;
            }
        }
    }
}

void fillConflicttArray()
{
    for(int i=0 ; i<NUMBER_SUBJECTS ; i++)
    {
        for(int j=i ; j<NUMBER_SUBJECTS ; j++)
        {
            for(int k=0 ; k<NUMBER_STUDENTS ; k++)
            {
                if(registeration[k][i] == 1 && registeration[k][j] == 1)
                {
                    conflict[i][j]++;
                }
            }
            conflict[j][i] = conflict[i][j];
        }
    }
}

int fillTimeSlots()
{
    int subjectsCount = NUMBER_SUBJECTS;
    int isSubjectTaken[NUMBER_SUBJECTS] = {0};
    for(int i=0 ; i<NUMBER_SUBJECTS ; i++)
    {
        for(int j=0 ; j<NUMBER_SUBJECTS ; j++)
        {
            if(isSubjectTaken[j] == 0)
            {
                days[i][j] = 1;
                isSubjectTaken[j] = 1;
                subjectsCount--;
                for(int k=0 ; k<j ; k++)
                {
                    if(days[i][k] == 1)
                    {
                        if(isConflict(j, k))
                        {
                            days[i][j] = 0;
                            isSubjectTaken[j] = 0;
                            subjectsCount++;
                            break;
                        }
                    }
                }
            }
            if(subjectsCount == 0)
            {
                return i+1;
            }
        }
    }
    return NUMBER_SUBJECTS;
}

int main()
{
    /* initialize random seed: */
//    srand(time(NULL));
    randomize();
    for(int r=0 ; r< NUMBER_STUDENTS ; r++)
    {
        for(int c=0 ; c<NUMBER_SUBJECTS ; c++)
        {
            cout<<registeration[r][c] << " ";
        }
        cout<<endl;
    }
    cout <<"--------------------------"<<endl;
    fillConflicttArray();
    for(int r=0 ; r< NUMBER_SUBJECTS ; r++)
    {
        for(int c=0 ; c<NUMBER_SUBJECTS ; c++)
        {
            cout<<conflict[r][c] << " ";
        }
        cout<<endl;
    }
    cout <<"--------------------------"<<endl;
    int nGroups = fillTimeSlots();
    for(int r=0 ; r< nGroups ; r++)
    {
        for(int c=0 ; c<NUMBER_SUBJECTS ; c++)
        {
            cout << days[r][c] << " ";
        }
        cout<<endl;
    }
    cout <<"--------------------------"<<endl;
    cout << "g = " << nGroups;
    /*
    for(int r=0 ; r<=99 ; r++)
    {
        for(int c=0 ; c<30 ; c++)
        {
            cout<<data[r][c];
        }
        cout<<endl;
    }
    */

    return 0;
}
