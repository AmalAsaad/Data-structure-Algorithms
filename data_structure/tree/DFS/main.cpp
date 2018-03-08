#include <iostream>

using namespace std;
//DFS

struct Tree
{
    char name, father;
    int order;
};
class mystack
{
private:
    char *arr;
    int top, size ;
public:
    mystack()
    {
        top=0;
        size=10;
        arr=new char[size];
    }
    mystack(int ss)
    {
        size=ss;
        top=0;
        arr=new char[size];
    }
    void push(char data)
    {
        arr[top++]=data;
    }
    char pop()
    {
        return arr[--top];

    }
     bool is_empty(){return (top==0);}

    bool isfull(){return (top==size);}
};
/*لتعريف الدالة اسفل ال
 main
 mainلازم اعرف دي فوق مشان يقراها قبل ما يدخل على
 وبعدين ينزل يشوف امبليمنتيشن بتاعها تحت
*/


//void print_DFS(Tree* , int);
void print_DFS(Tree *ptr, int size)
{
    int k, count ;
    char *sons;
    sons=new char[size];
    mystack st;
    for(k=0; k<size; k++)
        if(ptr[k].father=='0')
        {
            st.push(ptr[k].name);
            break;
        }
        char temp;

        while(!st.is_empty())
        {
            temp=st.pop();
            cout<<temp<<"\t";
            count=0;
            for(k=0; k<size; k++)
            if(ptr[k].father==temp)
            {
              sons[ptr[k].order]=ptr[k].name;
              count++;
            }
            for(k=count; k>=1; k--)
                st.push(sons[k]);


        }
}
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
  cout<<"the dfs :"<<"\n";
print_DFS(array,12);

}


