#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <string>

class BigDecimalInt
{
    public:
        std::string str;
    public:
        BigDecimalInt(std::string str);
        BigDecimalInt operator+ (BigDecimalInt &num);
        BigDecimalInt operator- (BigDecimalInt &num);
        virtual ~BigDecimalInt();

};

#endif
