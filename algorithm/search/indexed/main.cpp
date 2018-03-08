#include <iostream>

using namespace ;
struct index
{
    int val,slot;
};

int index_search(int data,data_size, struct index idz[],idx_size,key)
{
    int ret ,i, size;
    if(key<idx[0].val)
        return-1;
    while(key>=idx[i+1.val] && i<idx_size-1 )
    {
        i++;
        /**want to know the size of block we will search in it */
        //if he was last block
        if(i==idx_size-1)
          size =data_size - idx[i].slot;
        else
            size=idx[i+1].slot - idx[i].slot;
        ret=linear(size,key,& data[idx[i].slot] );
        if(ret>=0)
        {
            ret=ret+idx[i].slot;
            return ret;
        }

    }


}

int main()
{
   int data,
}
