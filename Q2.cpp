#include <iostream>
#include <string>
#include <algorithm>

int count_palindromes(std::string strings[], int size, std::string palindromes[]) {
    int num_palindromes = 0;

    for (int i = 0; i < size; i++) {
        std::string s = strings[i];
        std::string reversed_s = s;
        std::reverse(reversed_s.begin(), reversed_s.end());

        if (s == reversed_s) {
            palindromes[num_palindromes] = s;
            num_palindromes++;
        }
    }

    return num_palindromes;
}

int main() {
    std::string strings[] = {"apple", "banana", "orange", "grape", "noon", "tenet", "pop", "watermelon", "kiwi", "mango", "pineapple"};
    std::string palindromes[11];

    int num_palindromes = count_palindromes(strings, 11, palindromes);

    for (int i = 0; i < num_palindromes; i++) {
        std::cout << palindromes[i] << " ";
    }

    return 0;
}
