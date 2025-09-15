#include <iostream>
using namespace std;

// find the sum of positive factors of n
int sumFactors( int n );

int main()
{
	int numCases;
	cin >> numCases;
	for( int i = 1; i <= numCases; i++ )
	{
		int n;
		cin >> n;

		// n is equal to the sum of positive factors of n
		if( n == sumFactors( n ) )
			cout << "perfect number" << endl;
		else
			cout << "non-perfect number" << endl;
	}
}

int sumFactors( int n )
{
	  int sum = 0;
    for (int i=1 ; i<n ; ++i)
      if (n%i == 0 )
        sum = sum + i;
    return sum;
}
