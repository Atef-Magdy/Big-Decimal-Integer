#include <iostream>
#include "BigDecimalInt.h"

using namespace std;

int main()
{
    BigDecimalInt num1("3333333333333333333333");
    BigDecimalInt num2("1111111111");
    BigDecimalInt sum = (num1+num2);
    cout << sum.str;

    return 0;
}
