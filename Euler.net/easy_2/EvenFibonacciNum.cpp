// Sum of even-valued terms in fibonacci not exceeding 4,000,000

#include <iostream>
#include <map>

std::map<int, long> memo;

long fibonacci(int n)
{
    if(n <= 1) 
        return n;

    if(memo.count(n))
        return memo[n];

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main()
{
    long fib, value = 0, max = 4000000;

    for(int i = 1; fib <= max; i++)
    {
        fib = fibonacci(i);

        if(fib >= max)
            break;

        value += (fib % 2 == 0) ? fib : 0;
    }

    std::cout << "Sum of even-valued terms: " << value;
}