#include <iostream>
#include <stdio.h>
#include <stdlib.h>


55555
using namespace std;
#define NUMBER_STUDENT 100
#define NUMBER_SUBJECT 30
#define STUDENT_SUBJECT 5


int registration [NUMBER_STUDENT][NUMBER_SUBJECT]={0};
int conflict  [NUMBER_SUBJECT][NUMBER_SUBJECT]={0};
int days [NUMBER_SUBJECT][NUMBER_SUBJECT]={0};

void randomize ()
{

    for(int r=0 ; r<NUMBER_STUDENT  ; r++)
    {
        int  counter=0;
        while(counter<STUDENT_SUBJECT)
        {
            int n=rand()%NUMBER_SUBJECT ;
            if(registration[r][n]==0)
            {
                registration[r][n]=1;
                counter++;
            }


        }

    }

}
void fillconflict()
{
 for(int int i=0; i<NUMBER_SUBJECT; i++)
        for(int j=o ;j<)





}


int main()
{
    randomize();
    cout<<"the register matrix"<<"\n";
    for(int i=0 ;i<NUMBER_STUDENT; i++)
    {
       for(int j=0; j<NUMBER_SUBJECT; j++)
       {
           cout<<registration[i][j]<<" ";
       }
        cout<<endl;
    }




}
