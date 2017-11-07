/*
Chef goes to the market to buy a laptop. He enters a shop which has n laptops on display. Cost of ith laptop is c[i].

Chef wants to buy a single laptop by paying least amount of money. But there is an issue: when there are two or more laptops available at the same cost, he gets confused about which one he should buy, so in turn, he can't buy any of those.

Find the minimum amount of money he needs to pay to buy a single laptop. It is guaranteed that there is always a way to buy a laptop.

Input
First line of the input contains contains a single integer T denoting number of test cases.
For each test case there will be two lines.
First line of each test case will contain a single integer n denoting number of laptops available.
Second line of each test case will contain n space separated integers denoting array c i.e. c[1], c[2], .., c[n] as defined in the problem.
Output
For each test case, print a single line containing a single integer denoting minimum amount of money needed for Chef to buy a laptop.
Constraints
1 ≤ T, n ≤ 100
1 ≤ c[i] ≤ 100
Example
Input:
3
2
1 2
3
1 1 2
6
3 5 4 4 3 3
Output:
1
2
5
Explanation
Example case 1. He can buy the cheapest laptop i.e. cost = 1.

Example case 2. He can't buy any laptop with cost 1 because there are more than 1 (i.e. 2) such laptops and Chef will be confused in choosing. So he will choose the unique laptop with cost = 2.

Example case 3. He can't buy any of the laptops with cost 3 because there are more than 1 (i.e. 3) such laptops and Chef will be confused in choosing. Similarly, he also can't buy laptops with cost 4. So he will choose the unique laptop with cost = 5.
*/

// #include <iostream>
// using namespace std;



// int main()
// {
//     int t;
//     cin >> t;
//     int n;
//     int min, min_prev;
//     while (t--)
//     {
//         min = 101;
//         cin >> n;
//         int *arr;
//         arr = new int[n];
//         int num;
//         for (int i = 0; i < n; i++)
//         {
//             cin >>num ;
//             for(int j=0;j<n;j++)
//             {
//                 if(arr[j] == num)
//                 {
//                     arr[j] = -1;
//                 }else{
//                     arr[i] = num;
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cout<<arr[i];
//         }
//     }

//     return 0;
// }

#include <iostream>
#include<algorithm>
using namespace std;
 
int main() {
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,i,flag=1;
		cin>>n;
		n=n+1;
		long long int a[n];
		a[0]=0;
		for(i=1;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		for(i=1;i<n;i++)
		{
			if((a[i]!=a[i+1])&&(a[i]!=a[i-1]))
			{
				cout<<a[i]<<"\n";
				break;
			}
 
		}
 
 
	}
	return 0;
}