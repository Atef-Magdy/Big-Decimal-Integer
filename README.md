# Big-Decimal-Integer
Big Decimal Integer with overloading (+) and (-) operators.

    ///main cpp

    


    /// BigDecimalInt .h

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

     ///BigDecimalInt.cpp

     #include "BigDecimalInt.h"
    #include <iostream>

    using namespace std;

    BigDecimalInt::BigDecimalInt(string str)
    {
        this->str = str;
    }

    BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt &num){

            if(str.size() > num.str.size()){

                    int zeros = str.size() - num.str.size();
                    for(int i = 0 ; i < zeros ; i++) num.str = "0" + num.str;
            }
            else if(num.str.size() > str.size()){

                    int zeros = num.str.size() - str.size();
                    for(int i = 0 ; i < zeros ; i++) str = "0" + str;
            }

            int carry=0;
            for(int i = str.size()-1 ; i >= 0 ; --i){

                    if (char(int(str[i]-48) + int(num.str[i]-48) + 48 + carry ) >57){
                            str[i] = char(int(str[i]-48) + int(num.str[i]-48) + 38 + carry);
                            carry = 1;
                    }
                    else{
                            str[i] = char(int(str[i]-48) + int(num.str[i]-48) + 48 + carry);
                            carry=0;
                    }
            }
            if (carry == 1) str = "1" + str;

            return str;
    }

    BigDecimalInt BigDecimalInt::operator-(BigDecimalInt &num){

        bool First = false , Second = false , mins = false;
        if(str.size() > num.str.size()){
            First = true;
            int zeros = str.size() - num.str.size();
            for(int i=0 ; i < zeros ; i++) num.str = "0" + num.str;
        }

        else if(num.str.size() > str.size()){
            Second = true;
            mins = true;
            int zeros = num.str.size() > str.size();
             for(int i=0 ; i < zeros ; i++) str = "0" + str;
        }
        else{
            for(int i=0 ; i<str.size() ; i++){
                if(str[i] > num.str[i]){
                        First = true;
                        break;
                }
                else if (num.str[i] > str[i]){
                        Second = true;
                        mins = true;
                        break;
                }
            }
        }

        int borrow = 0;

        if(Second){
            string temp=str;
            str = num.str;
            num.str = temp;
        }

        for(int i = str.size()-1 ; i >= 0 ; i--){
            if(int(str[i]-48-borrow) > int(num.str[i]-48)){
                num.str[i] = char(int(str[i]-48) - int(num.str[i]-48)-borrow + 48);
                borrow=0;
            }
            else if(int(str[i]-48-borrow) < int(num.str[i]-48)){
                num.str[i] = char(int(str[i]-48)+10 - int(num.str[i]-48)-borrow + 48);
                borrow=1;
            }
            else if(int(str[i]-48) == int(num.str[i]-48)){
                num.str[i] = '0';
                borrow=0;
            }
        }
        if(mins) cout << "-";

        return num;
    }
    BigDecimalInt::~BigDecimalInt(){}
