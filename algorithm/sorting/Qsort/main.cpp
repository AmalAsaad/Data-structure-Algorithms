#include <iostream>

using namespace std;
template<class elemtype>
class Qsort
{
public:
    int n;
    void insert (int n)
    {
        list= new int[n];
        cout<<"enter the array"<<"\t";
        for(int i =0 ; i<n ; i++)
            cin>>list[i];
    }
    void print()
    {
        cout<<"the sorted array :";
        for(int i=0;i<n; i++)
        cout<<list[i]<<"\t";
    }


    void Qs()
    {
        requick(0,n-1);
    }


private:
    int *list;
    int partition(int f, int l)
    {
        int index,small_index;
        int part_ele;
        small_index= f;
        swap( f , (f+l)/2 );
        part_ele=list[f];
        for(index=f ; index<=l;index++)
        {
            if(part_ele>list[index])
            {
                small_index++;
                swap(index,small_index);
            }

        }
        swap(f,small_index);
        return small_index;

    }
     void swap (int first, int second)
    {
        int temp;
        temp =list[first];
        list[first]=list[second];
        list[second]=temp;

    }
     void requick(int f,int l)
    {
        if(f<l)
        {
            int eleloc = partition ( f, l);
            requick( f,eleloc-1);
            requick( eleloc+1,  l);

        }
    }
};


int main()
{
    Qsort <int> m;
    cout<<"enter the size of array wanted to be sort"<<"\t";
    cin>> m.n;
    m.insert(m.n);
    m.Qs();
    m.print();
    system("pause");
}
