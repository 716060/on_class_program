/*************************************************************************
	> File Name: args_templete.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 19时56分13秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

template<typename T>
void print(const T &a) {
    cout << a << endl;
}

template<typename T, typename ...ARGS>
void print(const T &a, ARGS ...args) {
    cout << a << " ";
    print(args...);
    return ;
}

template<typename T, typename ...ARGS>
struct ARG {
    typedef T getT;
    typedef ARG<ARGS...> rest;
};

template<typename T> 
struct ARG<T> {
    typedef T getT;
    typedef T finalT;
};

template<typename T, typename ..ARGS> class Test;
typename<typename T, typename ...ARGS>
class Test<ARGS...> {
public :
    T operator()()
};

int main() {
    print(123, "hello woeld", 12.2, 'o');
    cout << sizeof(ARG<int, double, float>::getT) << endl;
    cout << sizeof(ARG<int, double, float>::rest::getT) << endl;
    cout << sizeof(ARG<int, double, float>::rest::rest::getT) << endl;
    ARG<int, double, float>::getT a = 123;
    ARG<int, double, float>::rest::getT b = 123.45;
    ARG<int, double, float>::rest::rest::getT c = 123.3;
    cout << a << " " << b << " " << c << endl;
    return 0;
}
