#include<iostream>
#include <math.h>
using namespace std;

int Karatsuba(int Num1, int LenNum1, int Num2, int LenNum2)
{
    if(Num1 <= 10 || Num2 <= 10)
        return Num1*Num2;
    int n = max(LenNum1, LenNum2);
    //cout << n << endl;
    int half = n/2;
    int power = pow(10, half);

    int a = Num1 / power;
    int b = Num1 % power;
    int c = Num2 / power;
    int d = Num2 % power;
    int ac = Karatsuba(a, LenNum1/2, c, LenNum2/2);
    int bd = Karatsuba(b, LenNum1/2, d, LenNum2/2);
    int ad_bc = Karatsuba(a+b, LenNum1/2, c+d, LenNum2/2) - ac- bd;
    return ((ac * pow(10, 2*half)) + (ad_bc) * pow(10, half) + bd);

}

int main()
{
    int Num1,  Num2;
    int LenNum1,  LenNum2;
    cout << "Enter first number and its length :" ;
    cin >> Num1 ;
    cin >> LenNum1;
    cout << "\nEnter first number and its length :" ;
    cin >> Num2 ;
    cin >> LenNum2;
    cout << Karatsuba(Num1, LenNum1, Num2, LenNum2);
}