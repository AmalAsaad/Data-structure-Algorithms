#include <iostream>
using namespace std;
//to insert item to sorted list  .
//have to fun first to search the place where should item inserted. >>by using binary search.
//second fun to make (shift) all array down to make the finded place empty and could (insert )item .
class addsorted
{
private:
    int *arr=new int[maxsize];
    void insert_item(int loc,int key)

    {
        if(loc<0 ||loc>=maxsize)
            cout<<"out the range"<<endl;
        else if(lengh>=maxsize)
            cout<<"full list"<<endl;
        else
        {
            for(int r=lengh; r>loc; r--)
                arr[r]=arr[r-1];
            arr[loc]=key;
            lengh++;
        }

    }

public:
    int maxsize,lengh, r;
    void printnewarray()
    {
        cout<<"the new array with new item inserted "<<endl;
        for( r=0; r<lengh; r++)
            cout<<arr[r]<<"\t";
    }
    void insertarr(int n)
    {
        maxsize=n;
        cout<<"enter the array"<<endl;
        for( r=0; r<lengh; r++)
            cin>>arr[r];
        cout<<endl;
    }
    int insert_order(int key)
    {
        int first=0,last=lengh-1;
        bool found=false;
        //tow check before while
        //if array empty
        if(lengh==0)
        {
            cout<<"the array is empty "<<endl;
            arr[0]=key;
        }
        //check if array full
        else if(lengh==maxsize)
            cout<<"can;t insert into full array"<<endl;

        while(!found && first<=last)
        {
            int mid=(first+last)/2;
            //check for dublicated
            if(key==arr[mid])
            {
                found=true;
                cout<<"is already excit duplicated not allow"<<endl;
            }
            else if(key<arr[mid])
                last=mid-1;
            //check if key larger should put it after mid
            else
            {
                first=mid+1;
                //find location should insert it
                mid++;
                insert_item(mid,key);
            }
        }
    }





};
int main()

{
    int key;
    addsorted d;
    cout<<"enter the total size of list"<<endl;
    cin>>d.maxsize;
    cout<<"enter the lengh"<<endl;
    cin>>d.lengh;
    cin>>d.lengh;
    d.insertarr(d.maxsize);
    cout<<"enter the key want to insert it"<<endl;
    cin>>key;
    d.insert_order(key);
    d.printnewarray();


}
