#include <iostream>

using namespace std;
class mergesorted
{
private:
    int *arr,r;
    void merge(int lf, int ll,int rf, int rl)
    {
        int *temp=new int[lengh];
        //first time only <mean start index from here ,but then index will change and move
        int index=lf;
        //so should save it,to know where temp start from, so we can assign it final in original (arr)
        int savef=lf;
        //3 while
        while((lf<=ll)&&(rf<=rl))
        {
            if(arr[lf]<arr[rf])
            {
                temp[index]=arr[lf];
                lf++;
            }
            else
            {
                temp[index]=arr[rf];
                rf++;
            }
            index++;
        }
        while(lf<=ll)
        {
            temp[index]=arr[lf];
            lf++;
            index++;
        }
        while(rf<=rl)
        {
            temp[index]=arr[rf];
            rf++;
            index++;
        }
        //reassign temp to arr
        for(r=savef; r<=rl; r++ )
            arr[r]=temp[r];


    }
public:
    int lengh;
    void merge_sort(int f,int l)
    {
        if(f<l)
        {
            int mid=(f+l)/2;
            merge_sort(f,mid);
            merge_sort(mid+1,l);
            merge(f,mid,mid+1,l);
        }
    }

    void print()
    {
        cout<<"the new sorted array  :"<<endl;
        for(r=0; r<lengh; r++)
            cout<<arr[r]<<"\t";
    }
    void insert(int n)
    {
        lengh=n;
        arr=new int[lengh];
        cout<<"enter the array plz"<<endl;
        for(r=0; r<lengh; r++)
            cin>>arr[r];
    }
};


int main()
{
    mergesorted m;
    cout<<"enter the size of array"<<endl;
    cin>>m.lengh;
    m.insert(m.lengh);
    m.merge_sort(0,m.lengh-1);
    m.print();
    system("pause");
}
