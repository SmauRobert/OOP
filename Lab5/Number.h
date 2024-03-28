#pragma once

class Number {
    // add data members
    char *Digits;
    int DigitsCount, Base;

    long long int GetBase10Value() const;
public:
    Number(const char * value, int base=10);   // where base is between 2 and 16
    Number(int value);
    Number(const Number& num);              // copy constructor
    Number(Number&& num);             // move constructor
    ~Number();

    // index operator
    char operator [](const int index);
    
    // relational operators
    bool operator >(const Number& num);
    bool operator <(const Number& num);
    bool operator >=(const Number& num);
    bool operator <=(const Number& num);
    bool operator ==(const Number& num);
    bool operator !=(const Number& num);

    // arithmetic operators
    friend Number operator +(const Number& num1, const Number& num2);
    friend bool operator +=(Number& num1, Number& num2); 
    friend Number operator -(const Number& num1, const Number& num2);
    friend bool operator -=(Number& num1, Number& num2);

    // move assignment operator
    Number& operator =(Number && num);
    Number& operator =(int value);

    // -- operator
    bool operator --();
    bool operator --(int value);

    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
};