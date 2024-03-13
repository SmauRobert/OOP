#include "Math.h"
#include <stdarg.h>

int Math::Add(int a, int b) {
    return a + b;
}

int Math::Add(int a, int b, int c) {
    return a + b + c;
}

int Math::Add(double a,double b) {
    return (int)(a + b);
}

int Math::Add(double a, double b, double c) {
    return (int)(a + b + c);
}

int Math::Mul(int a,int b) {
    return a * b;
}

int Math::Mul(int a,int b,int c) {
    return a * b * c;
}

int Math::Mul(double a, double b) {
    return (int)(a * b);
}

int Math::Mul(double a, double b, double c) {
    return (int)(a * b * c);
}

int Math::Add(int count, ...) {// sums up a list of integers
    int ans = 0;
    va_list Nums;
    va_start(Nums, count);
    for(int i = 0; i < count; i ++) {
        int x = va_arg(Nums, int);
        ans += x;
    }
    va_end(Nums);

    return ans;
}

#include <stdio.h>

char* Math::Add(const char *str1, const char *str2) {
    if(str1 == nullptr || str2 == nullptr)
        return nullptr;

    int lgans = 1, lga = 0, lgb = 0;
    for(int i = 0; str1[i]; i ++)
        lga ++;

    for(int i = 0; str2[i]; i ++)
        lgb ++;

    if(lga < lgb) lgans += lgb;
    else lgans += lga;

    char *ans = new char[lgans + 1];
    ans[lgans] = '\0';
    
    int t = 0, index = lgans - 1;
    for(int a = lga - 1, b = lgb - 1; a >= 0 || b >= 0; a --, b --) {
        int sa = (a >= 0 ? str1[a] - '0' : 0);
        int sb = (b >= 0 ? str2[b] - '0' : 0);

        ans[index --] = (sa + sb + t) % 10 + '0';
        t = (sa + sb + t) / 10;
    }

    if(t) ans[index --] = t + '0';
    
    if(index == 0) {
        for(int i = 0; i < lgans - 1; i ++)
            ans[i] = ans[i + 1];
        ans[lgans - 1] = '\0';
    }

    return ans;
}