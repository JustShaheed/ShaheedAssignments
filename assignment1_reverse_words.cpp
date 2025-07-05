#include <iostream>
#include <string>
#include <cassert>
#include <cctype>

std::string reverseWord(std::string word) {
    int i = 0;
    int j = word.length() - 1;

    while (i < j) {
        if (!isalnum(word[i])) {
            i++;
            continue;
        }

        if (!isalnum(word[j])) {
            j--;
            continue;
        }

        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;

        i++;
        j--;
    }

    return word;
}

std::string reverse_words(const std::string& input) {
    std::string result = "";
    std::string current = "";

    for (int i = 0; i < input.length(); ++i) {
        if (input[i] != ' ') {
            current += input[i];
        } else {
            if (current != "") {
                result += reverseWord(current);
                current = "";
            }
            result += " ";
        }
    }

    if (current != "") {
        result += reverseWord(current);
    }

    return result;
}

int main() {
    std::string test = "String; 2be reversed...";
    std::string expected = "gnirtS; eb2 desrever...";
    std::string actual = reverse_words(test);

    std::cout << "Result: " << actual << std::endl;
    assert(actual == expected);
    return 0;
}
