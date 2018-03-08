#include <iostream>
//generate 10 random numbers
//store odd and even num in separated stacks
//print the num from stacks

using namespace std;
class mystack
{
public:
    mystack()
    {
         size=100;
         top=0;
         arr =new int [size];
    }
    mystack(int ss)
    {
         size=ss;
         top=0;
         arr =new int [size];

    }
    void push (int n)
    {
        arr[top]=n;
        top++;
    }
    int pop()
    {
        return arr[--top];
    }
    bool is_empty()
    {
        return (top==0);

    }
    bool is_full()
    {
        return(top ==size);

    }
    int get_size()
    {
        return size;
    }
    int get_actualLengh()
    {
        return top;
    }
    void Double_size()
    {
        int *temp=new int [size*2];
        for(int k=0 ;k<size ;k++)
          temp[k]=arr[k];
        size=size*2;
        delete arr;
        arr=temp;
    }
private:
    int *arr ,top ,size;


};

int main()
{
  int n;
  mystack odd(6);
  mystack even(6) ;
  cout<<"the random generated num"<<endl;
  for(int k=1;k<=10;k++)
  {
     n=rand()%100;
    cout<<n<<"\n";
     if(n%2==0)
  {
      if (even.is_full()==true)
         even.Double_size();
      even.push(n);
  }
  else
  {
      if(!odd.is_full())
         odd.push(n);
      else
         cout<<"odd stack is full"<<endl;

  }
  }


      cout<<"number from odd stack :"<<"\n";
        while(odd.is_empty()==false)
          cout<< odd.pop()<<"\n";

      cout<<"number from even stack :\n";
        while(!even.is_empty())
          cout<< even.pop()<<"\n";

       cout<<"num of odd numbers is "<<odd.get_actualLengh()<<endl;
       cout<<"num of even numbers is "<<even.get_actualLengh()<<endl;
       cout<<"max num of odd numbers"<<odd.get_size()<<endl;
       cout<<"max num of even numbers"<<even.get_size()<<endl;










}
