#include <iostream>

using namespace std;
class insertionsorted
{
private:
    int *arr;
public:
    int lengh,r;
    void print()
    {
        cout<<"the new sorted array :"<<endl;
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
    void insertion()
    {
        int firstoutoforder;
        int loc,temp;
        /**inside loop**/
        for(firstoutoforder=1; firstoutoforder<lengh; firstoutoforder++)
        {
            if(arr[firstoutoforder]<arr[firstoutoforder-1])
            {
                temp=arr[firstoutoforder];
                loc=firstoutoforder;
                /** اخرج كل ده برهif */
                do
                {
                    arr[loc]=arr[loc-1];
                    loc--;
                }
                while(loc>0 && arr[loc-1]>temp);
                arr[loc]=temp;
            }
        }

    }
};

int main()
{
    insertionsorted s;
    cout<<"enter the size of array"<<endl;
    cin>>s.lengh;
    s.insert(s.lengh);
    s.insertion();
    s.print();


}
