#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

unordered_map<string, string> anagrams(string word, string word_list[], int n) {
    string sorted_word = word;
    sort(sorted_word.begin(), sorted_word.end());
    sorted_word.erase(remove(sorted_word.begin(), sorted_word.end(), ' '), sorted_word.end());

    unordered_map<string, string> anagrams_dict;

    for (int i = 0; i < n; i++) {
        string w = word_list[i];
        string sorted_w = w;
        sort(sorted_w.begin(), sorted_w.end());
        sorted_w.erase(remove(sorted_w.begin(), sorted_w.end(), ' '), sorted_w.end());

        if (anagrams_dict.count(sorted_w) > 0) {
            anagrams_dict[sorted_w] += ", " + w;
        }
        else {
            anagrams_dict[sorted_w] = w;
        }
    }

    unordered_map<string, string> result;
    if (anagrams_dict.count(sorted_word) > 0) {
        result[sorted_word] = anagrams_dict[sorted_word];
    }

    return result;
}

int main() {
    string word = "listen";
    string word_list[] = {"enlists", "google", "inlets", "banana"};
    int n = sizeof(word_list) / sizeof(word_list[0]);

    unordered_map<string, string> result = anagrams(word, word_list, n);

    for (auto it = result.begin(); it != result.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
