#include<bits/stdc++.h>

using namespace std;

int main() {
    // Part 1: Total Combinations
    int total_combinations = 6 * 6;
    cout << "1. Total Combinations: " << total_combinations << endl;

    // Part 2: Distribution Matrix
    vector<vector<pair<int, int>>> distribution_matrix(6, vector<pair<int, int>>(6, {0, 0}));

    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            distribution_matrix[i-1][j-1] = {i, j};
        }
    }

    // Display the distribution matrix
    cout << "\n2. Distribution Matrix:" << endl;
    for (const auto& row : distribution_matrix) {
        for (const auto& pair : row) {
            cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        cout << endl;
    }

    // Part 3: Probability of Sums
    total_combinations = 6 * 6;

    // Count occurrences of each sum
    vector<int> sum_counts(12, 0);

    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            sum_counts[i + j - 2]++;
        }
    }

    unordered_map<int, int> total_occurrences;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            total_occurrences[distribution_matrix[i][j].first + distribution_matrix[i][j].second]++;
        }
    }

    cout << "\nProbability of Possible Sums:" << endl;
    for (int sum_value = 2; sum_value <= 12; sum_value++) {
        int occurrences = total_occurrences[sum_value];
        int  probability = (occurrences) / total_combinations;
        cout << "Probability sum of " << sum_value << " is " << occurrences << "/" << total_combinations << endl;
    }

    return 0;
}
