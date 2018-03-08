#include <iostream>

using namespace std;
class heapsort
{
public:
    int r,lengh;
    void insert (int n)
    {
        lengh=n;
        arr= new int[lengh];
        cout<<"enter the array"<<endl;
        for( r =0 ; r<lengh ; r++)
            cin>>arr[r];
    }
    void print()
    {
        cout<<"the sorted array :";
        for(r=0; r<lengh; r++)
            cout<<arr[r]<<"\t";
    }
    void heap_sort()
    {
        int temp;
       // int l=0;
        Build_heap();
        //print();
        for(r=lengh-1; r>=0; r--)
        {
            // swap(l,r-1);
            temp=arr[r];
            arr[r]=arr[0];
            arr[0]=temp;
            heapfy(0,r-1);

        }


    }



private:
    int *arr;
    void heapfy(int low, int high)
    {
        int temp=arr[low];
        int largeindex=2*low+1;
        while(largeindex<=high)
        {
            if(largeindex<high)
            {
                if(arr[largeindex]<arr[largeindex+1])
                    largeindex=largeindex+1;
            }

            if(temp>arr[largeindex])
                break;


            else
            {
                arr[low]=arr[largeindex];
                low=largeindex;
                largeindex=2*low+1;
            }
            arr[low]=temp;
        }

    }
    void Build_heap()
    {
        for(r=(lengh/2)-1; r>=0; r--)
            heapfy(r,lengh-1 );
    }

    void swap(int first,int sec)
    {
        int temp=arr[first];
        arr[first]=arr[sec];
        arr[sec]=temp;
    }

};
int main()
{
    heapsort tree;
    cout<<"enter the size of matrix"<<endl;
    cin>>tree.lengh;
    tree.insert(tree.lengh);
    tree.heap_sort();
    tree.print();

}
