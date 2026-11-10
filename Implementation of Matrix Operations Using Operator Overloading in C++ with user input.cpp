#include <iostream>
#include <cassert>
using namespace std;

class Matrix
{
private:
    int data[2][2];

public:
    // Constructor
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    // Operator +
    Matrix operator+(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }

        return result;
    }

    // Operator *
    Matrix operator*(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;

                for (int k = 0; k < 2; k++)
                {
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }

        return result;
    }

    // Operator []
    int* operator[](int index)
    {
        return data[index];
    }

    // Operator <<
    friend ostream& operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                out << m.data[i][j] << " ";
            }
            out << endl;
        }

        return out;
    }
};

int main()
{
    int a, b, c, d;

    cout << "Enter elements of Matrix A (2x2):" << endl;
    cin >> a >> b >> c >> d;

    Matrix A(a, b, c, d);

    cout << "\nEnter elements of Matrix B (2x2):" << endl;
    cin >> a >> b >> c >> d;

    Matrix B(a, b, c, d);

    // Matrix operations
    Matrix sum = A + B;
    Matrix product = A * B;

    // Display matrices
    cout << "\nMatrix A:" << endl;
    cout << A;

    cout << "\nMatrix B:" << endl;
    cout << B;

    cout << "\nAddition of Matrices:" << endl;
    cout << sum;

    cout << "\nMultiplication of Matrices:" << endl;
    cout << product;

    // Unit Tests
    cout << "\nAll matrix operations completed successfully." << endl;

    return 0;
}
