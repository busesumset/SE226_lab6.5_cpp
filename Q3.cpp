#include <iostream>
#include <cmath>

int* sieve_of_eratosthenes(int* numbers, int length, int& primes_length) {
    int* primes = new int[length];
    bool* sieve = new bool[numbers[length - 1] + 1];

    // Initialize the sieve array to true
    std::fill_n(sieve, numbers[length - 1] + 1, true);

    sieve[0] = sieve[1] = false;

    for (int i = 2; i <= std::sqrt(numbers[length - 1]); i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= numbers[length - 1]; j += i) {
                sieve[j] = false;
            }
        }
    }

    primes_length = 0;
    for (int i = 0; i < length; i++) {
        if (sieve[numbers[i]]) {
            primes[primes_length++] = numbers[i];
        }
    }

    delete[] sieve;
    return primes;
}

int main() {
    int numbers[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    int primes_length;
    int* primes = sieve_of_eratosthenes(numbers, length, primes_length);

    for (int i = 0; i < primes_length; i++) {
        std::cout << primes[i] << " ";
    }

    delete[] primes;
    return 0;
}
