// Tywin Lannister is a tactical genius. At the heart of his tactical skills, is the way he has organized his armies, and the way he is able to estimate his soldiers' skill-levels, thus helping him make crucial decisions as to whom to dispatch to which areas of the war.

// His army is organized in the form of a hierarchy - indeed it is a tree, with him as the root. We say "A has immediate superior B" if A reports directly to B. We further say "A has superior B" if there is a chain of soldiers starting with A, ending with B, and where each soldier reports directly to the next soldier of the chain. Further, each soldier is assigned an initial skill-level based on prior experience and battle proficiency.

// In order for Tywin to decide whom to send to which battle, he has the following scheme: He chooses a particular soldier S as the leader of his temporary 'regiment', and sends in to battle, S as well as all the soldiers that have S as one of their superiors. He estimates the skill level of the regiment as the total skill level of all the soldiers under S (denoted by query "Q S").

// After a battle, he may want to update the skill levels of some soldiers. If he wants to update the skill level of soldier S to value x, it is denoted by the query "U S x".

// You are given the structure of the army, whose size is N, the initial skill levels of all the individual soldiers, as well the number of queries M. For each query of the type "Q S", report the sum of skill-levels of all the soldiers who have S as their superior.

// Note: The soldiers are numbered 1 to N, and Tywin is given the number 1.

// Input
// The first line consists of the integers N and M, denoting the number of soldiers and the number of queries.
// This is followed by a single line consisting of N nonnegative values - the skill levels of the N soldiers.
// This is then followed by N-1 lines consisting of pairs of integers (u, v), denoting that either u is an immediate superior of v, or vice-versa.
// Finally you are given the M queries, of either the form "U S x" or "Q S".

// Output
// For each "Q S" query, output the sum of skill values of all the soldiers under S.

// Constraints
// 1 ≤ N ≤ 105
// 1 ≤ M ≤ 105
// All skill values given with be in the range [0, 20,000]
// 1 ≤ S ≤ N for all queries
// All soldiers will have soldier 1 (Tywin) as their superior
// Example
// Input:
// 5 8
// 7 2 0 5 8
// 1 2
// 2 3
// 2 4
// 1 5
// Q 1
// Q 2
// U 2 4
// Q 1
// Q 2
// U 5 3
// Q 1
// Q 2

// Output:
// 22
// 7
// 24
// 9
// 19
// 9
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> a;
vector<int> p;
long int f(int x)
{
    int y = p[x];
    long int tink;
    if (x == 1)
    {
        return a[0];
    }
    tink = f(y-1);
    if (tink + 1 < a[x])
    {
        return a[x];
    }
    else if (tink + 1 == a[x])
    {
        return tink + 1;
    }
    else
    {
        cout << "ERROR";
        return -1;
    }
}

long int g( int x)
{
    long int y = p[x];
    long int tink;
    if (x == 1)
    {
        return 1;
    }
    tink = g(y-1);
    if (tink + 1 < a[x])
    {
        return 1;
    }
    else if (tink + 1 == a[x])
    {
        cout<<tink;
        return tink + 1;
    }
    else
    {
        cout << "ERROR";
        return -1;
    }
}

int main()
{
    p.push_back(0);
    long int n, q, q_copy;

    cin >> n;
    cin >> q;

    int a_temp;
    int p_temp;

    for (int i = 0; i < n; i++)
    {
        cin >> a_temp;
        a.push_back(a_temp);
    }

    for (int i = 1; i < n; i++)
    {
        cin >> p_temp;
        p.push_back(p_temp);
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {

            long int x;
            long int newval;
            cin >> x;
            cin >> newval;

            a[x - 1] = newval;
        }
        if (type == 1)
        {
            long int x;
            cin >> x;

            long int fx = f(x-1);
            long int gx = g(x-1);
            cout << fx << endl;
            cout << gx << endl;
        }
    }

    return 0;
}
