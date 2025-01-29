#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

int fib(int n) {
    if (n <= 1) {
        return 1;
    }

    atomic<int> result1(0), result2(0);

    auto compute_fib_n1 = [&]() { result1 = fib(n - 1); };
    auto compute_fib_n2 = [&]() { result2 = fib(n - 2); };

    thread t1(compute_fib_n1);
    thread t2(compute_fib_n2);

    t1.join();
    t2.join();

    return result1 + result2;
}

int main() {
    int n = 19;

    unsigned int max_threads = thread::hardware_concurrency();
    cout << "avaliable threads: " << max_threads << endl;

    int result = fib(n);
    cout << "fib result for n = " << n << " is " << result << endl;

    return 0;
}
