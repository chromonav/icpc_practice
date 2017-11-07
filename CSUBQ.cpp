// Chef has an array A consisting of N non-negative integers. Initially, all the elements are zero. Assume 1-based indexing. Chef is given two positive integers L and R. (L <= R) Chef has to execute Q number of queries on the array A. These queries can be of the following two types:

// 1 x y (1 ≤ x ≤ n) - Replace the value of xth array element by y.

// 2 l r (1 ≤ l ≤ r ≤ n) - Return the number of subarrays [a , b] that lies in subarray [l , r] such that the value of the maximum array element in that subarray is atleast L and atmost R.

// (A subarray [a , b] lies in a subarray [l , r] if and only if a >= l and b <= r)

// Since, Chef couldn't solve this task, can you please help him solve this task?

// Input
// The first line contains four space separated positive integers N, Q, L and R denoting the total number of elements in an array, total number of queries, value of L, and value of R respectively.
// Each of the next Q lines contains one of the two queries described above.

// Output
// For each query of type 2, print the required answer in a new line.

// Constraints
// 1 ≤ N, Q ≤ 5 * 10^5

// 1 ≤ L ≤ R ≤ 10^9

// 1 ≤ l ≤ r ≤ N

// 1 ≤ x ≤ N

// 1 ≤ y ≤ 10^9

// Subtasks
// Subtask #1 (10 points) : 1 ≤ N , Q ≤ 100

// Subtask #2 (15 points) : 1 ≤ N , Q ≤ 5000

// Subtask #3 (27 points) : 1 ≤ Q ≤ 10^4

// Subtask #4 (48 points) : Original Constraints

// Example
// Input:

// 5 6 1 10

// 1 1 2

// 2 1 5

// 1 3 11

// 1 4 3

// 2 3 5

// 2 1 5

// Output:

// 5

// 2

// 4
// Explanation
// Query 1.

// A = {0, 0, 0, 0, 0}

// After replacing value of 1st element by 2,

// A = {2, 0, 0, 0, 0}

// Query 2.

// A = {2, 0, 0, 0, 0}

// All the subarrays that lies in a subarray [1 , 5] whose maximum value is atleast 1 and atmost 10 are -

// [1 , 1], [1 , 2], [1 , 3], [1 , 4] and [1 , 5]. Thus the answer is 5.

// Query 3.

// A = {2, 0, 0, 0, 0}

// After replacing value of 3rd element by 11,

// A = {2, 0, 11, 0, 0}

// Query 4.

// A = {2, 0, 11, 0, 0}

// After replacing value of 4th element by 3,

// A = {2, 0, 11, 3, 0}

// Query 5.

// A = {2, 0, 11, 3, 0}

// All the subarrays that lies in a subarray [3 , 5] whose maximum value is atleast 1 and atmost 10 are -

// [4 , 4] and [4 , 5]. Thus the answer is 2.

// Query 6.

// A = {2, 0, 11, 3, 0}

// All the subarrays that lies in a subarray [1 , 5] whose maximum value is atleast 1 and atmost 10 are -

// [1 , 1], [1 , 2], [4 , 4] and [4 , 5]. Thus the answer is 4.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    long long int n, q;
    long int l, r;
    long int y;

    cin >> n >> q >> l >> r;
    int *arr;
    arr = new int[n];

    while (q--)
    {
        int optype, x, y;

        cin >> optype >> x >> y;

        if (optype == 1)
        {
            arr[x - 1] = y;
        }
        // cout << "\n"
        //      << "Array:";
        // for (int k = 0; k < n; k++)
        // {
        //     cout << arr[k] << ", ";
        // }
        // cout << endl;
        if (optype == 2)
        {
            int main_count = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] >= l && arr[i] <= r)
                {
                    continue;
                }
                else
                {
                    int sub_count = 0;
                    for (int j = i + 1; j < n; j++)
                    {
                        if (arr[j] >= l && arr[j] <= r)
                        {
                            sub_count++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    main_count += sub_count;
                }
            }
            cout << main_count;
        }
    }

    // for (int k = 0; k < n; k++)
    // {
    //     cout << arr[k] << ", ";
    // }
    // cout << endl;

    return 0;
}