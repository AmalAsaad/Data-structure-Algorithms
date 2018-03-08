#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST

#ifdef TEST
#define NUMBER_SUBJECTS 4
#define NUMBER_STUDENTS 100
#define STUDENT_SUBJECT 2
#endif // TEST

#ifndef TEST
#define NUMBER_SUBJECTS 30
#define NUMBER_STUDENTS 100
#define STUDENT_SUBJECT 5
#endif // TEST




using namespace std;

int registeration[NUMBER_STUDENTS][NUMBER_SUBJECTS] = {0};
int conflict[NUMBER_SUBJECTS][NUMBER_SUBJECTS] = {0};
int days[NUMBER_SUBJECTS][NUMBER_SUBJECTS] = {0};
int minGroup = NUMBER_SUBJECTS+1;
int optimumDays[NUMBER_SUBJECTS][NUMBER_SUBJECTS] = {0};




void randomize()
{
    for(int r=0 ; r< NUMBER_STUDENTS ; r++)
    {
        int counter = 0;

        while(counter < STUDENT_SUBJECT)
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
bool isConflict(int s1, int s2)
{
    if(conflict[s1][s2] > 0)
        return true;
    else
        return false;
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


void fillTimeSlotsOPTIMUM()
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
//                cout<<"here"<<endl;
                if(i+1 < minGroup)
               {
                    minGroup = i+1;
//                   cout << "min = " <<minGroup<<endl;
                    for(int r=0 ; r< NUMBER_SUBJECTS ; r++)
                        for(int c=0 ; c<NUMBER_SUBJECTS ; c++)
                            optimumDays[r][c] = days[r][c];
                }
                days[i][j] = 0;
                isSubjectTaken[j] = 0;
                subjectsCount++;
            }
            if(i == NUMBER_SUBJECTS-1 && j == NUMBER_SUBJECTS-1)
            {
                if(days[i][j] == 1)
                {
                    days[i][j] = 0;
                    isSubjectTaken[j] = 0;
                    subjectsCount++;
                }
                i=-1;
                j=-1;
                for(int m=0 ; m<NUMBER_SUBJECTS ; m++)
                    for(int n=0 ; n<NUMBER_SUBJECTS ; n++)
                        if(days[m][n] == 1)
                        {
                            i=m;
                            j=n;
                        }

                if(i==-1 && j==-1)
                    return;

                days[i][j] = 0;
                isSubjectTaken[j] = 0;
                subjectsCount++;
            }
        }
    }
}

int main()
{
    /* initialize random seed: */
#ifndef TEST
    srand(time(NULL));
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
#endif // TEST

#ifdef TEST
    conflict[0][0] = conflict[0][1] = conflict[1][0] = conflict[1][1] = conflict[1][3] = conflict[2][2] = conflict[2][3] = conflict[3][1] = conflict[3][2] = conflict[3][3] = 1;
#endif // TEST

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
    cout << "g = " << nGroups << endl;
    cout <<"--------------------------"<<endl;
    fillTimeSlotsOPTIMUM();
    for(int r=0 ; r< minGroup ; r++)
    {
        for(int c=0 ; c<NUMBER_SUBJECTS ; c++)
        {
            cout << optimumDays[r][c] << " ";
        }
        cout<<endl;
    }
    cout <<"--------------------------"<<endl;
    cout << "gMin = " << minGroup;
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
