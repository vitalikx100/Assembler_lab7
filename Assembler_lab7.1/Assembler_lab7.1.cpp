#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // 2^((x + lnx)* log2(5))
    double result, x;
    double c5 = 5.0;
    cout << "Input x: ";
    cin >> x;
    _asm
    {
        finit;
        fldln2; st(0) = ln(2)
        fld x; st(0) = x; st(1) = ln(2)
        fyl2x; st(0) = ln(x)
        fld x; st(0) = x; st(1) = ln(x)
        fadd st, st(1); st(0) = x + lnx
        fld1; st(0) = 1
        fld c5; st(0) = 5; st(1) = 1; st(2) = x + lnx
        fyl2x; st(0) = log2(5); st(1) = x + lnx
        fmulp st(1), st; st(0) = (x + lnx) * log2(5)        

        fstp result;
      

    }
     
    cout << "asm: " << pow(2,result) << endl;
    cout << "C++: " << pow(5, x + log(x));
}