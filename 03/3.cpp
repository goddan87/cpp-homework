#include <iostream>
using namespace std;

void division(int dividend[], int divisor[], int quotient[], int remainder[],
              int dividendDegree, int divisorDegree, int &quotientDegree, int &remainderDegree);

const int arraySize = 101;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int dividend[arraySize];
        int dividendDegree;
        cin >> dividendDegree;
        for (int i = dividendDegree; i >= 0; i--)
            cin >> dividend[i];

        int divisor[arraySize];
        int divisorDegree;
        cin >> divisorDegree;
        for (int i = divisorDegree; i >= 0; i--)
            cin >> divisor[i];

        int quotient[arraySize];
        int remainder[arraySize];
        int quotientDegree;
        int remainderDegree;
        division(dividend, divisor, quotient, remainder,
                 dividendDegree, divisorDegree, quotientDegree, remainderDegree);

        cout << quotientDegree;
        for (int i = quotientDegree; i >= 0; i--)
            cout << " " << quotient[i];
        cout << endl;

        cout << remainderDegree;
        for (int i = remainderDegree; i >= 0; i--)
            cout << " " << remainder[i];
        cout << endl;
    }
}

void division(int dividend[], int divisor[], int quotient[], int remainder[],
              int dividendDegree, int divisorDegree, int &quotientDegree, int &remainderDegree)
{
    int buffer[arraySize];
    int bufferDegree;
    for (int i = 0; i <= dividendDegree; i++)
        remainder[i] = dividend[i];
    remainderDegree = dividendDegree;
    bufferDegree = remainderDegree;
    quotientDegree = remainderDegree - divisorDegree;
    for (int i = 0; i < arraySize; i++)
        buffer[i] = 0;
    for (int i = 0; i < arraySize; i++)
        quotient[i] = 0;
    while (remainderDegree >= divisorDegree)
    {
        quotient[remainderDegree - divisorDegree] = remainder[remainderDegree] / divisor[divisorDegree];
        for (int i = bufferDegree; i >= bufferDegree - divisorDegree; i--)
        {
            buffer[i] = quotient[remainderDegree - divisorDegree] * divisor[i - bufferDegree + divisorDegree];
        }
        for (int i = remainderDegree; i >= 0; i--)
        {
            remainder[i] -= buffer[i];
        }
        for (int i = 0; i < arraySize; i++)
            buffer[i] = 0;
        remainderDegree--;
        bufferDegree--;
    }
    while (remainderDegree != 0 && remainder[remainderDegree] == 0)
        remainderDegree--;
}