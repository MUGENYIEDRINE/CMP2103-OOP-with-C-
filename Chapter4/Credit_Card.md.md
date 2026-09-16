# Credit Card Number Validation in C++

## Description

This C++ program validates a credit card number using the **Luhn algorithm**.

The program checks:

1. The credit card number has between **13 and 16 digits**.
2. The number starts with a valid prefix:
   - `4` — Visa
   - `5` — MasterCard
   - `37` — American Express
   - `6` — Discover
3. The Luhn checksum is valid.

## Source Code

```cpp
#include <iostream>
using namespace std;

bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main()
{
    long long number;
    cout << "Enter credit card number: ";
    cin >> number;

    if (isValid(number))
        cout << number << " is valid" << endl;
    else
        cout << number << " is invalid" << endl;

    return 0;
}

bool isValid(long long number)
{
    return (getSize(number) >= 13 && getSize(number) <= 16) &&
           (prefixMatched(number, 4) || prefixMatched(number, 5) ||
            prefixMatched(number, 37) || prefixMatched(number, 6)) &&
           ((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0);
}

int sumOfDoubleEvenPlace(long long number)
{
    int sum = 0;
    bool isEvenPlace = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (isEvenPlace)
        {
            sum += getDigit(digit * 2);
        }

        isEvenPlace = !isEvenPlace;
        number /= 10;
    }

    return sum;
}

int getDigit(int number)
{
    if (number < 10)
        return number;
    else
        return number / 10 + number % 10;
}

int sumOfOddPlace(long long number)
{
    int sum = 0;
    bool isEvenPlace = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (!isEvenPlace)
        {
            sum += digit;
        }

        isEvenPlace = !isEvenPlace;
        number /= 10;
    }

    return sum;
}

bool prefixMatched(long long number, int d)
{
    return getPrefix(number, getSize(d)) == d;
}

int getSize(long long d)
{
    int size = 0;

    while (d > 0)
    {
        size++;
        d /= 10;
    }

    return size;
}

long long getPrefix(long long number, int k)
{
    int size = getSize(number);

    if (size < k)
        return number;
    else
    {
        for (int i = 0; i < size - k; i++)
            number /= 10;

        return number;
    }
}
```

## Function Summary

| Function | Purpose |
|---|---|
| `isValid()` | Checks whether the credit card number is valid |
| `sumOfDoubleEvenPlace()` | Doubles and sums every second digit |
| `getDigit()` | Adds the digits when a doubled value is two digits |
| `sumOfOddPlace()` | Sums the digits in the remaining positions |
| `prefixMatched()` | Checks whether the number starts with a required prefix |
| `getSize()` | Counts the number of digits |
| `getPrefix()` | Extracts the first `k` digits |

## Luhn Algorithm

The validation formula is:

```text
(sum of doubled even-place digits
 + sum of odd-place digits) % 10 == 0
```

If the remainder is `0`, the credit card number passes the Luhn check.

## Example

Input:

```text
Enter credit card number: 4388576018402626
```

Output:

```text
4388576018402626 is valid
```

## Important Note

A number passing the Luhn algorithm does **not** prove that a real credit card exists or that it is active. It only means that the number satisfies the required format, prefix, length, and checksum rules.
