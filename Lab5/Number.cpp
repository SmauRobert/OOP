#include "Number.h"
#include <stdio.h>
#include <cstdlib>

Number::Number(const char * value, int base) : Base(base) { // where base is between 2 and 16
    if(value == nullptr || value[0] == '\0') {
        this->Digits = new char[1];
        Digits[0] = '0';
        return;
    }

    for(this->DigitsCount = 0; value[this->DigitsCount]; this->DigitsCount ++);

    this->Digits = new char[this->DigitsCount];
    for(int i = 0; i < this->DigitsCount; i ++)
        Digits[i] = value[i];
}

Number::Number(int value) : Base(10) {
    if(value == 0) {
        this->Digits = new char[1];
        Digits[0] = '0';
        return;
    }
    int copy = value;
    for(this->DigitsCount = 0; copy > 0; this->DigitsCount ++, copy /= 10);
    this->Digits = new char[this->DigitsCount];
    for(int i = this->DigitsCount - 1; i >= 0; i --) {
        Digits[i] = value % 10 + '0';
        value /= 10;
    }
}

Number::Number(const Number& num) : Base(num.Base), DigitsCount(num.DigitsCount) {  // copy constructor
    this->Digits = new char [this->DigitsCount];
    for(int i = 0; i < this->DigitsCount; i ++)
        this->Digits[i] = num.Digits[i];
}

Number::Number(Number&& num) : Base(num.Base), DigitsCount(num.DigitsCount) { // move constructor
    char *temp = num.Digits;
    num.Digits = nullptr;
    this->Digits = temp;
}

Number::~Number() {
    delete[] Digits;
}

// index operator
char Number::operator[](const int index) {
    if(index < 0 || index >= this->DigitsCount) {
        printf("Cannot index %d in number %.*s!\n", index, this->DigitsCount, this->Digits);
        exit(-1);
    }
    return this->Digits[index];
}

// relational operators
bool Number::operator >(const Number& num) {
    return GetBase10Value() > num.GetBase10Value();
}

bool Number::operator <(const Number& num) {
    return GetBase10Value() < num.GetBase10Value();
}

bool Number::operator >=(const Number& num) {
    return GetBase10Value() >= num.GetBase10Value();
}

bool Number::operator <=(const Number& num) {
    return GetBase10Value() <= num.GetBase10Value();
}

bool Number::operator ==(const Number& num) {
    return GetBase10Value() == num.GetBase10Value();
}

bool Number::operator !=(const Number& num) {
    return GetBase10Value() != num.GetBase10Value();
}


// arithmetic operators
Number operator +(const Number& num1, const Number& num2) {
    Number copy1 = num1;
    Number copy2 = num2;
    if(num1.Base < num2.Base) copy1.SwitchBase(num2.Base);
    else if(num1.Base > num2.Base) copy2.SwitchBase(num1.Base);

    int lgsum = 1;
    if(copy1.DigitsCount > copy2.DigitsCount) lgsum += copy1.DigitsCount;
    else lgsum += copy2.DigitsCount;

    char *Sum = new char[lgsum];

    int t = 0, index = lgsum - 1;
    for(int i1 = copy1.DigitsCount - 1, i2 = copy2.DigitsCount - 1; i1 >= 0 || i2 >= 0; i1 --, i2 --) {
        int d1 = 0, d2 = 0;
        if(i1 >= 0) {
            if(copy1.Digits[i1] >= 'A') d1 = copy1.Digits[i1] - 'A' + 10;
            else d1 = copy1.Digits[i1] - '0';
        }

        if(i2 >= 0) {
            if(copy2.Digits[i2] >= 'A') d2 = copy2.Digits[i2] - 'A' + 10;
            else d2 = copy2.Digits[i2] - '0';
        }

        int result = (d1 + d2 + t) % copy1.Base;
        
        if(result >= 10) Sum[index --] = 'A' + result - 10;
        else Sum[index --] = result + '0';

        t = (d1 + d2 + t) / copy1.Base;
    }

    if(t) Sum[index --] = '1';

    if(index == 0) {
        for(int i = 0; i < lgsum - 1; i ++)
            Sum[i] = Sum[i + 1];
        Sum[lgsum - 1] = '\0';
    }

    Number ans(Sum, copy1.Base);
    return ans;
}

bool operator +=(Number& num1, Number& num2) {
    num1 = num1 + num2;
    return true;
}

Number operator -(const Number& num1, const Number& num2) { // Assumes num1 > num2
    Number copy1 = num1;
    Number copy2 = num2;
    if(num1.Base < num2.Base) copy1.SwitchBase(num2.Base);
    else if(num1.Base > num2.Base) copy2.SwitchBase(num1.Base);

    int lgdiff = 0;
    if(copy1.DigitsCount > copy2.DigitsCount) lgdiff = copy1.DigitsCount;
    else lgdiff = copy2.DigitsCount;


    char *Diff = new char[lgdiff];

    int t = 0, index = lgdiff - 1;
    for(int i1 = copy1.DigitsCount - 1, i2 = copy2.DigitsCount - 1; i1 >= 0 || i2 >= 0; i1 --, i2 --) {
        int d1 = 0, d2 = 0;
        if(i1 >= 0) {
            if(copy1.Digits[i1] >= 'A') d1 = copy1.Digits[i1] - 'A' + 10;
            else d1 = copy1.Digits[i1] - '0';
        }

        if(i2 >= 0) {
            if(copy2.Digits[i2] >= 'A') d2 = copy2.Digits[i2] - 'A' + 10;
            else d2 = copy2.Digits[i2] - '0';
        }

        int result = d1 - d2 + t;
        if(result < 0) {
            result += copy1.Base;
            t = -1;
        } else t = 0;

        if(result >= 10) Diff[index --] = 'A' + result - 10;
        else Diff[index --] = result + '0';
    }

    if(index > 0) {
        for(int i = 0; i < lgdiff - index; i ++)
            Diff[i] = Diff[i + index - 1];
        Diff[lgdiff - index] = '\0';
    }

    Number ans(Diff, copy1.Base);
    return ans;
}

bool operator -=(Number& num1, Number& num2) {
    num1 = num1 - num2;
    return true;
}

// move assignment operator
Number& Number::operator =(Number && num) {
    this->Base = num.Base;
    this->DigitsCount = num.DigitsCount;

    char *temp = num.Digits;
    num.Digits = nullptr;
    this->Digits = temp;

    return (*this);
}

Number& Number::operator =(int value) {
    if(value == 0) {
        delete[] this->Digits;
        this->Digits = new char[1];
        Digits[0] = '0';
        return (*this);
    }
    int copy = value, oldBase = this->Base;
    for(this->DigitsCount = 0; copy > 0; this->DigitsCount ++, copy /= 10);
    this->Digits = new char[this->DigitsCount];
    this->Base = 10;
    for(int i = this->DigitsCount - 1; i >= 0; i --) {
        Digits[i] = value % 10 + '0';
        value /= 10;
    }
    this->SwitchBase(oldBase);
    return (*this);
}

bool Number::operator --() {
    for(int i = 0; i < this->DigitsCount - 1; i ++)
        this->Digits[i] = this->Digits[i + 1];
    this->DigitsCount --;
    this->Digits[this->DigitsCount] = '\0';
    return true;
}

bool Number::operator --(int value) {
    this->DigitsCount --;
    this->Digits[this->DigitsCount] = '\0';
    return true;
}


long long int Number::GetBase10Value() const { // TODO: replace 'long long int value' with a BigInt implementation
    long long int value = 0;
    for(int i = 0; i < this->DigitsCount; i ++) {
        if(this->Digits[i] >= 'A') value = value * this->Base + (this->Digits[i] - 'A' + 10);
        else value = value * this->Base + (this->Digits[i] - '0');
    }
    return value;
}

void Number::SwitchBase(int newBase) {  
    if(this->DigitsCount == 1 && this->Digits[0] == '0') {
        this->Base = newBase;
        return;
    }

    long long int value = GetBase10Value();

    delete[] this->Digits;
    this->DigitsCount = 0;
    this->Base = newBase;

    for(int copy = value; copy > 0; copy /= this->Base) this->DigitsCount ++;

    this->Digits = new char[this->DigitsCount];

    for(int i = this->DigitsCount - 1; i >= 0; i --) {
        long long int rest = value % this->Base;
        value /= this->Base;

        if(rest >= 10) this->Digits[i] = 'A' + rest - 10;
        else this->Digits[i] = '0' + rest;
    }
}

void Number::Print() {
    printf("%.*s\n", this->DigitsCount, this->Digits);
}

int Number::GetDigitsCount() { // returns the number of digits for the current number
    return this->DigitsCount;
}

int Number::GetBase() { // returns the current base
    return this->Base;
}