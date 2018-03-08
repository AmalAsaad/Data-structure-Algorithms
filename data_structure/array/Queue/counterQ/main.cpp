#include <iostream>

using namespace std;
//circular queue <<< by using % for each tow pointers (r & f)
//2nd problem is when (r==f) it may be (empty) or (full)
//solve problem when it empty & when it full by using
//( counter )
class myque
{
private:
    int *arr,f,r,size;
public:
    int counter;
    myque()
    {
        size=50;
        arr=new int[size];
        f=r=counter=0;

    }
    myque(int ss)
    {
        size=ss;
        arr=new int[size];
        f=r=counter=0;

    }
    void enque(int n)
    {
        arr[r]=n;
        r=(r+1)%size;
        counter++;
    }
    int deque()
    {
        int temp =arr[f];
        f=(f+1)%size;
        counter--;
        return temp;

    }
    bool is_full()
    {
        return counter==size;
    }
    bool is_empty()
    {
        return counter==0;
    }
    int get_size()
    {
        return size;
    }
    int get_actaullenght()
    {
        return counter;

    }
    void double_size()
    {
        int *temp;
        temp =new int[size*2];
        for(int k=0; k<size; k++)
            temp[k]=arr[(k+f)%size];
        f=0;
        r=counter;
        size=size*2;   //hint
        delete arr;
        arr=temp;



    }
};
//generate 10 random numbers
//store in queue
//print these num from q
int main()
{
    myque ah (10);
    cout<<"the random num :"<<"\n";
    for(int k=0; k<10 ; k++)
    {
        int n=rand ()%50 ;
        cout<<n<<"\n";
        if(ah.is_full())
            ah.double_size();
        ah.enque(n);
    }
    cout<<"num of numbers in q"<< ah.get_actaullenght()<<endl;
    cout<<"max num in q" << ah.get_size()<<endl;
    cout<<"---------------------------"<<endl;

    while(!ah.is_empty())
    {
        cout<<ah.deque()<<"\n";
    }


return 0;

}
