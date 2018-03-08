#include <iostream>

using namespace std;
template<class elemtype>
class add_sorted
{
private:
    int *list;
    void insertAT(int loc,const int item);
public:
    int lengh,maxsize;
    void insert_order(const int item);
    void print();
    void inserT(int n);

};
template<class elemtype>
void add_sorted<elemtype>:: insertAT(int loc,const int item)
    {
         //the loc where item should be inserted.
        if(loc<0 || loc>=maxsize) //not understand
          cout<<"out of range"<<endl;

        else
               if(lengh==maxsize)

                   cout<<"full list"<<endl;
                else
                {

                    for(int i=lengh; i>loc; i--)
                        list[i]=list[i-1];
                    list[loc]=item;
                    lengh++;

                }


    }

template<class elemtype>
void add_sorted<elemtype>::insert_order(const int item)
    {
        int first=0;
        int last=lengh-1;
        bool found=false;
        int mid;
        if(lengh==0)
           {
               list[0]=item;
               lengh++;
           }
        else if(lengh==maxsize)
            cout<<"can't insert into full list"<<endl;
        else
        {
            while(first<=last&&!found)
            {
                 mid=(first+last)/2;
                if(item==list[mid])
                    found=true;
                else if(item<list[mid])
                    last=mid-1;
                else
                    first=mid+1;
            }
            if(found)
                cout<<"insert item is already exist in list"<<"duplicated aren't allow"<<endl;
            else if (item>list[mid])
            {
                mid++; //the location where item should insert (find specific loc)
                insertAT(mid,item);
            }

        }
    }
template<class elemtype>
void add_sorted<elemtype>::inserT(int n)
    {
        lengh=n;
        cout<<"enter the list"<<"\t";
        list=new int[n];
        for(int i=0; i<n; i++)
            cin>>list[i];
    }
template<class elemtype>
void add_sorted<elemtype>:: print()
    {
        cout<<"the new array with item :"<<"\n";
        for(int i=0; i<lengh; i++)
         cout<<list[i]<<"\t";
    }


int main(void)
{
    int item;
    add_sorted <int> ob;
    cout<<"enter the size of array"<<"\n";
    cin>>ob.maxsize;
    cout<<"enter the lengh of arry"<<"\n";
    cin>>ob.lengh;
    cout<<"enter the item "<<"\n";
    cin>>item;
    ob.inserT(ob.lengh);
    ob.insert_order(item);
    ob.print();

}
