// де F(n) - числа Фібоначчі:
// C(n,k) - біноміальні коефіцієнти:
// F(0) = 1, F(1) = 1, F(n) = F(n-1) + F(n-2),
// C(n,k) = 1, якщо k = 0 або k = n,
// C(n,k) = C(n-1,k-1) + C(n-1,k), інакше.

#include <iostream>
using namespace std;

int Fib(const int n, const int level, int& depth);
int C(const int n, const int k, const int level, int& depth);
int SumC(const int n, const int k, const int level, int& depth);

int main()
{
    int n;
    cout << "n = "; cin >> n;

    // числа Фібоначчі
    int depth = 0;                          // початкове значення глибини
    cout << "Fib(" << n << "):" << endl;
    int f = Fib(n, 1, depth);               // 1 - початкове значення рівня
    cout << "F(" << n << ") = " << f << endl;
    cout << "depth = " << depth << endl << endl;

    // сума біноміальних коефіцієнтів
    depth = 0;
    cout << "SumC(" << n << ", 0):" << endl;
    int s = SumC(n, 0, 1, depth);
    cout << "SUM = " << s << endl;
    cout << "depth = " << depth << endl << endl;

    if (f == s) // перевірка чи збіглися значення
        cout << "F(n) = SUM C(n-k,k): formula is true" << endl;
    else
        cout << "F(n) <> SUM C(n-k,k): formula is false" << endl;

    return 0;
}

// Число Фібоначчі
int Fib(const int n, const int level, int& depth)
{
    if (level > depth)
        depth = level;
    // вивід значення поточного рівня рекурсії
    cout << " level = " << level << endl;

    if (n > 1)
        return Fib(n - 1, level + 1, depth)
        + Fib(n - 2, level + 1, depth);
    else
        return 1;
}

// Біноміальний коефіцієнт C(n, k)
int C(const int n, const int k, const int level, int& depth)
{
    if (level > depth)
        depth = level;
    // вивід значення поточного рівня рекурсії
    cout << " level = " << level << endl;

    if (k > 0 && k < n)
        return C(n - 1, k - 1, level + 1, depth)+ C(n - 1, k, level + 1, depth);
    else
        return 1;
}

// Сума C(n-k, k) для k від поточного значення до n/2
int SumC(const int n, const int k, const int level, int& depth)
{
    if (level > depth)
        depth = level;
    // вивід значення поточного рівня рекурсії
    cout << " level = " << level << endl;

    if (k <= n / 2)
        return C(n - k, k, level + 1, depth)
        + SumC(n, k + 1, level + 1, depth);
    else
        return 0;
}