#include <iostream>

using namespace std;
//BFS
  struct Tree
{
    char names, father;
    int order;
};
class my
{
private:
    int f ,r ,size,counter;
    char *arr;
public:
    my()
    {
        size=10;
        f=r=counter=0;
        arr= new char[size];

    }
    my(int m)
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
    struct Tree array[13]=
    {
    {'A','B',3},
    {'B','C',1},
    {'C','0',0},
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

cout<<"the Bfs :"<<endl;
print_BFS(array,13);

}
void print_BFS(Tree*arr,int size)
{
    char *sons=new char[size];
    int counter;
    my m;
    for(int k=0; k<size; k++)
      if(arr[k].father=='0')
      {
         m.enqueue(arr[k].names);
         break;
      }
      char temp;

      while(!m.is_empty())
      {
          temp=m.dequeue();
          cout<<temp<<"\t";
          counter=0;

          for(int k=0; k<size; k++)
            if(arr[k].father==temp)
            {
                sons[arr[k].order]=arr[k].names;
                counter++;
            }
         for(int r=1; r<=counter; r++) //why should start r from 1 not 0>>>because we start order from 1 not 0 ,there id not sons will enq in sons[0]
            m.enqueue(sons[r]);

      }


}

