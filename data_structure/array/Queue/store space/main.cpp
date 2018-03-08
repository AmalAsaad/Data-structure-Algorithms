#include <iostream>

using namespace std;
//circular queue <<< by using (%size) for each tow pointers (r & f)
////2nd problem is when (r==f) it may be (empty) or (full)
//solve problem when it empty & when it full by using
//(store  additional space )
class myque
{
private:
    int f,r,size;
    int *arr;
public:
    myque()
    {
        size=100;
        f=0;
        r=0;
        arr =new int [size];

    }
    myque(int ss)
    {
        size=ss;
        f=r=0;
        arr =new int [size];

    }
    void enque(int n)
    {
        arr[r]=n;
        r=(r+1)% size; //circular
    }
    int deque()
    {
        int temp;
        temp=f;
        f=(f+1) % size;  //circular

        return arr[temp];
    }
    bool is_empty()
    {
        return r==f;
    }
    bool is_full()
    {
       return (r+1)%size == f ; //store space (r=f-1)
    }
    int get_size()
    {
        return size;
    }
    int get_actualLength()
    {
       return (r-f + size)% size;  //store space
    }
    void double_size()
    {
        int *temp=new int [size*2];
        for(int k=0;k<size ;k++)
            temp[k]=arr[(k+f)%size];
        f=0;
        r=get_actualLength(); //hint
        size = size*2;
        delete arr;
        arr=temp ;

    }

};

int main()
{
     myque ah (10);
    cout<<"the random num :"<<"\n";
    for(int k=0; k<10 ; k++)
    {
        int n=rand ()%50 ;
        cout<<n<<"\n";
        if(ah.is_full()==true)
            ah.double_size();
        ah.enque(n);
    }
    cout<<"num of numbers in q"<<"\n"<< ah.get_actualLength()<<endl;
    cout<<"max num in q"<<"\n" << ah.get_size()<<endl;
    cout<<"-------------"<<endl;
    while(!ah.is_empty())
    {
        cout<<ah.deque()<<"\n";
    }


    return 0;
}
