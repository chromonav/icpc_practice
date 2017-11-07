#include <stdio.h>
#include <iostream>
#include <math.h>
#include<vector>
using namespace std;
void printPowerSet(vector<int> arr, int set_size)
{
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    int set_size = arr.size();
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
 
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j))
            cout<<arr[j];
       }
       printf("\n");
    }
}
 
/*Driver program to test printPowerSet*/
int main()
{
    vector<int> arr = {1,2,3,4};
    printPowerSet(arr, 3);
 
    return 0;
}