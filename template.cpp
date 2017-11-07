#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;
int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int n = 3;
int min_check(int k1, int k2)
{
    if (k1 > k2)
    {
        return 1;
    }
    else if (k1 == k2)
    {
        return 0;
    }
    else if (k1 < k2)
    {
        return -1;
    }
}

int check(int arr1[], int arr2[])
{
    int temp;
    vector<int> check;
    for (int i = 0; i < 3; i++)
    {
        temp = min_check(arr1[i], arr2[i]);
        check.push_back(temp);
    }
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << check[i];
    // }
    //ensure not equal;
    if ((check[0] == check[1]) && (check[0] == check[2]) && (check[0] == 0))
    {
        return 0;
    }

    if (check[0] >= 0 && check[1] >= 0 && check[2] >= 0)
    {
        return 1;
    }
    if (check[0] <= 0 && check[1] <= 0 && check[2] <= 0)
    {
        return 2;
    }

    return 0;
}

void main_check(int i, int j, int k)
{

    if (k == (n - 1))
    {
        cout << "yes";
    }
    else if (check(arr[i], arr[j]) == 2)
    {

        if (check(arr[i], arr[k + 1]) == 1)
        {
            return main_check(k + 1, j, k + 1);
        }
        else if (check(arr[j], arr[k + 1]) == 2)
        {
            return main_check(i, k + 1, k + 1);
        }
        else
        {
            cout << "no";
        }
    }
    else if (check(arr[i], arr[j]) == 1)
    {
        if (check(arr[i], arr[k + 1]) == 2)
        {
           return main_check(j,k+1,k+1);
        }
    }
    else
    {
        cout << "no";
    }
}
int main()
{

    main_check(0, 1);
    // int
    // int check_arr3_arr1 = check(arr3, arr1);
    // int check_arr3_arr2 = check(arr3, arr2);
    // int check_arr1_arr2 = check(arr1, arr2);
    // if ((check_arr1_arr2 == 0) || (check_arr3_arr2 == 0) || (check_arr3_arr1 == 0))
    // {
    //     cout << "no";
    // }else if (check_arr1_arr2 == 1)
    // {
    //     if (check_arr3_arr2 == 2)
    //     {
    //         cout << "yes";
    //     }
    //     else if (check_arr3_arr1 == 1)
    //     {
    //         cout << "yes";
    //     }
    //     else
    //     {
    //         cout << "no";
    //     }
    // }else{
    //     if(check_arr3_arr2 == 1)
    //     {
    //         cout<<"yes";
    //     }else if(check_arr3_arr1 == 2){
    //         cout<<"yes";
    //     }else{
    //         cout<<"no";
    //     }
    // }

    return 0;
}