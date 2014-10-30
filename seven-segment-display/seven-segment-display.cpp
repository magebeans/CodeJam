#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<string> digit_str = {
    "1111110",
    "0110000",
    "1101101",
    "1111001",
    "0110011",
    "1011011",
    "1011111",
    "1110000",
    "1111111",
    "1111011"
};

vector<long> digits(10);

int main() {
    int t, n;
    vector<string> state_str;
    vector<long> states;
    scanf("%d", &t);

    for (int i = 0; i < 10; i ++) {
        digits[i] = strtol(digit_str[i].to_c(), null, 2);
    }

    for (int i = 0; i < t; i ++) {
        scanf("%d", &n);
        states.resize(n);
        for (int j = 0; j < n; j ++) {
            scanf("%s", &state_str[j]);
            states[j] = strtol(state_str[j], null, 2);
        }

        for (int guess = 9; guess >= 0; guess--) {
            int prev_diff = guess ^ states[guess];
            for (int correct = guess, j = 0; j < states.size();
                    j++, correct = (correct == 0) ? (9) : (correct - 1)) {
                int diff = correct ^ states[guess];
                if (diff != prev_diff)

                }
        }


    }
}