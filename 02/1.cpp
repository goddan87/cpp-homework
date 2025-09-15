#include <iostream>
using namespace std;

int sumDigits( int number );

int main()
{
   int numCases;
   cin >> numCases;
   for( int i = 1; i <= numCases; i++ )
   {
      int n;
      cin >> n;
      cout << sumDigits( n ) << endl;
   }
}

int sumDigits( int n )
{
	int sum = 0;
    while (n > 0)
    {
      sum = sum + n%10;
    	n /= 10;
    }
    return sum;
}