#include <iostream>

using namespace std;
//BFS
  struct Tree
{
    char name, father;
    int order;
};
class myqueue
{
private:
    int f ,r ,size,counter;
    char *arr;
public:
    myqueue()
    {
        size=10;
        f=r=counter=0;
        arr= new char[size];

    }
    myqueue(int m)
    {
        r=f=counter=0;
        size=m;
        arr=new char[size];

    }
    void enqueue(char dd)
    {
        arr[r]=dd;
        r=(r+1)%size;
        counter++;
    }
    char dequeue()
    {
        char temp;
        temp=arr[f];
        f=(f+1)%size;
        counter--;
        return temp;
    }
    bool is_empty(){return (counter==0);}
    bool isfull(){return (counter==size);}

};

void print_BFS(Tree*,int);

int main()
{
    struct Tree array[12]=
    {
    {'A','B',3},
    {'B','C',1},
    {'C','0',1},
    {'D','E',1},
    {'E','C',2},
    {'F','G',1},
    {'G','E',2},
    {'H','A',2},
    {'I','B',2},
    {'J','A',1},
    {'K','A',3},
    {'L','B',1}
  };

cout<<"the Bfs :"<<"\n";
print_BFS(array,12);



}
void print_BFS(Tree *ptr,int size)
 {

    int count,k;
    char *sons;
    sons= new char [size];
    myqueue q;
    for( k=0; k<size; k++ )
        if(ptr[k].father =='0')
        {
           q.enqueue(ptr[k].name);
           break;
        }

    char temp;
    while(!q.is_empty())
      {
        temp=q.dequeue();
        cout<<temp<<"\t";
        count=0;
        for( k=0; k<size; k++)
            if(ptr[k].father==temp)
            {
                sons[ptr[k].order]=ptr[k].name ;
                count++;
            }
        for( k=1; k<=count ; k++)
            q.enqueue(sons[k]);
       }

 }






