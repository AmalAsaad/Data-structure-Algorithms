#include <iostream>

using namespace std;
class selectionsorted
{
private:
    int *arr;
    void swap (int first, int second)
    {
        int r;
        int temp;
        temp =arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
    int minvalue(int f,int l)
    {
        int r;
        int minindex=f;
        for(r=f; r<=l; r++)
            if(arr[r]<arr[minindex])
                minindex=r;
        return minindex;

    }
public:
    int lengh;
    void print()
    {
        int r;
        cout<<"the new sorted array  :"<<endl;
        for(r=0; r<lengh; r++)
            cout<<arr[r]<<"\t";
    }
    void insert(int n)
    {
        int r;
        lengh=n;
        arr=new int[lengh];
        cout<<"enter the array plz"<<endl;
        for(r=0; r<lengh; r++)
            cin>>arr[r];
    }
    void selection_sorted()
    {
        int r;
        int min;
        for(r=0; r<lengh; r++)
        {
            min=minvalue(r,lengh-1);
            swap(r,min);
        }

    }
};
int main()
{

    selectionsorted m;
    cout<<"enter the size of array"<<endl;
    cin>>m.lengh;
    m.insert(m.lengh);
    m.selection_sorted();
    m.print();
}
