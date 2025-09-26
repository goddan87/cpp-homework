#include <iostream>
#include <cmath>
using namespace ::std;

// returns true if and only if a and b have a common factor
bool haveCommonFactors(int a, int b);

int main()
{
    int numCases;
    cin >> numCases;
    for (int i = 1; i <= numCases; i++)
    {
        int a, b;
        cin >> a >> b;

        if (haveCommonFactors(a, b))
            cout << "not coprime" << endl;
        else
            cout << "coprime" << endl;
    }
}

bool haveCommonFactors(int x, int y)
{
    int a = x, b = y;
    while ((a %= b) && (b %= a))
        ;
    return (a + b != 1);
}