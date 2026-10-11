#include <iostream>
#include <string>

using namespace std;

    // (a) Calculate total contributions recursively

int totalContributions(int amounts[], int n) {

    if (n == 0) {
        return 0;
    }

    // Recursive case
    return amounts[n - 1] +
            totalContributions(amounts, n-1);
}

    // (b) Calculate the greatest common divisor recursively

int gcd(int a, int b) {

    if (b == 0) {
        return a;
    }

    // Recursive case: Euclid's algorithm

    return gcd(b, a % b);
}

    // (c) Check whether a string is a palindrome

bool isPalindrome(string code, int start, int end) {

     // Base case: all characters have matched

    if (start >= end) {
        return true;
    }

    // If the characters differ, it is not a palindrome

    if (code[start] != code[end]) {
        return false;
    }

    // Move inwards

    return isPalindrome(code, start + 1, end - 1);
}

    // (d) Count occurrences of a digit recursively

int countDigit(long long number, int digit) {
    // Base case

    if (number == 0) {
        return 0;
    }

    // Check the last digit

    int count = (number % 10 == digit) ? 1 : 0;

    // Remove the last digit and continue recursively

    return count + countDigit(number / 10, digit);
}
int main() {
    int amounts[] = {500, 750, 300, 450};

    cout << "Total collected: R"
         << totalContributions(amounts, 4) << endl;

    cout << "Largest equal group size: "
         << gcd(24, 36) << endl;

    cout << "4AB2BA4 is "
         << (isPalindrome("4AB2BA4", 0, 6)
             ? "valid" : "invalid") << endl;

    cout << "STOK21 is "
         << (isPalindrome("STOK21", 0, 5)
             ? "valid" : "invalid") << endl;

    cout << "Occurrences of 4 in 402414543: "
         << countDigit(402414543, 4) << endl;

    return 0;
}