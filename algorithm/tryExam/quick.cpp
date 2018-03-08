#include<iostram>
using namespace std;
class qq
{
public:
    int i,lengh;
    void insert (int n)
    {
        arr= new int[n];
        cout<<"enter the array"<<endl;
        for( i =0 ; i<n ; i++)
            cin>>list[i];
    }
    void print()
    {
        cout<<"the sorted array :";
        for(i=0; i<n; i++)
            cout<<list[i]<<"\t";
    }
    void Qs(int f, int l)
    {
        requick( f,  l);
    }
private:
    int *arr;
    void requick(int f, int l)
    {
        if(f<l)
        {
            int elem=partition( f,l);
            requick(f, elem-1);
            requick(elem+1, l);
        }
    }
    void swap(int first,int sec)
    {
        int temp=arr[first];
        arr[first]=arr[sec];
        arr[sec]=temp;
    }
    int partition(int f, int l)
    {
        int smallindex=f;
        int index;
        int partelem=arr[f];
        swap(f,(f+l)/2);
        while(f<l)
        {
            for(index=f; index<lengh; index++)
            {
                if(arr[index]<partelem)
                {
                    smallindex++;
                    swap(index,smallindex);
                }
            }
            swap(f,smallindex);
            return smallindex;
        }
    }

};
int main()
{
    qq obj;
    cout<<"enter the size of array"<<endl;
    cin>>obj.lengh;
    obj.insert(obj.lengh);
    obj.Qs(0,obj.lengh-1 );
    obj.print();

}
