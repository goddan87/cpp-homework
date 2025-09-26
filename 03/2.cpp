// Polynomial multiplication
#include <iostream>
using namespace std;

const int arraySize = 101;

// product = multiplicand * multiplier provided that
// neither multiplicand nor multiplier is the zero polynomial
void multiplication(int multiplicand[], int multiplier[], int product[],
                    int multiplicandDegree, int multiplierDegree, int &productDegree);

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int multiplicand[arraySize];
        int multiplicandDegree;
        cin >> multiplicandDegree;
        for (int i = multiplicandDegree; i >= 0; i--)
            cin >> multiplicand[i];

        int multiplier[arraySize];
        int multiplierDegree;
        cin >> multiplierDegree;
        for (int i = multiplierDegree; i >= 0; i--)
            cin >> multiplier[i];

        int product[2 * arraySize];
        int productDegree;
        multiplication(multiplicand, multiplier, product,
                       multiplicandDegree, multiplierDegree, productDegree);

        cout << productDegree;
        for (int i = productDegree; i >= 0; i--)
            cout << " " << product[i];
        cout << endl;
    }
}

// product = multiplicand * multiplier provided that
// neither multiplicand nor multiplier is the zero polynomial
void multiplication(int multiplicand[], int multiplier[], int product[],
                    int multiplicandDegree, int multiplierDegree, int &productDegree)
{
    productDegree = multiplicandDegree + multiplierDegree;
    for (int i = 0; i <= productDegree; ++i)
    {
        product[i] = 0;
    }
    for (int i = 0; i <= multiplicandDegree; ++i)
    {
        for (int j = 0; j <= multiplierDegree; ++j)
        {
            product[i + j] += multiplicand[i] * multiplier[j];
        }
    }
    while (productDegree != 0 && product[productDegree] == 0)
        productDegree--;
}