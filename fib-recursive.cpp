#include <iostream>
using namespace std;

int fib(int n) {
    if (n<=1) {
        return 1;
    } else {
        int n2 = fib(n-2);
        int n1 = fib(n-1);
        return n1+n2;
    }
}

int main() {
    int n = 100;
    int result = fib(n);

    cout << result;


    return 0;
}
