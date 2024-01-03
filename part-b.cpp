#include <bits/stdc++.h>

using namespace std;

void dice_a_combo(const vector<int>& elements, int length, vector<int>& current, vector<vector<int>>& all_combinations) {
    if (current.size() == length) {
        all_combinations.push_back(current);
        return;
    }
    for (int element : elements) {
        current.push_back(element);
        dice_a_combo(elements, length, current, all_combinations);
        current.pop_back();
    }
}

void dice_b_combo(const vector<int>& elements, int length, int start, vector<int>& current, vector<vector<int>>& all_combinations) {
    if (current.size() == length) {
        all_combinations.push_back(current);
        return;
    }
    for (int i = start; i < elements.size(); i++) {
        current.push_back(elements[i]);
        dice_b_combo(elements, length, i + 1, current, all_combinations);
        current.pop_back();
    }
}

vector<double> probsum(const vector<int>& arr1, const vector<int>& arr2) {
    vector<double> psum1(12, 0.0);
    for (int i : arr1) {
        for (int j : arr2) {
            int k = i + j;
            psum1[k - 1] += 1.0;
        }
    }
    for (double& p : psum1) {
        if (p != 0.0) {
            p /= 36.0;
        }
    }
    return psum1;
}

void transform(const vector<int>& die_a, const vector<int>& die_b) {
    vector<int> elements1 = {1, 2, 3, 4};
    int length = 6;
    vector<int> current;
    vector<vector<int>> combo1;
    dice_a_combo(elements1, length, current, combo1);

    vector<int> elements2 = {1, 2, 3, 4, 5, 6, 7, 8};
    int start = 0;
    vector<vector<int>> combo2;
    dice_b_combo(elements2, length, start, current, combo2);

    vector<double> psum = {0, 1.0 / 36, 2.0 / 36, 3.0 / 36, 4.0 / 36, 5.0 / 36, 6.0 / 36, 5.0 / 36, 4.0 / 36, 3.0 / 36, 2.0 / 36, 1.0 / 36};

    bool flag = false;
    for (const auto& i : combo1) {
        for (const auto& j : combo2) {
            if (probsum(i, j) == psum) {
                cout << "new die_a: ";
                for (int x : i) {
                    cout << x << " ";
                }
                cout << endl << "new die_b: ";
                for (int x : j) {
                    cout << x << " ";
                }
                cout << endl;
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
}

int main() {
    vector<int> die_a = {1, 2, 3, 4, 5, 6};
    vector<int> die_b = {1, 2, 3, 4, 5, 6};
    transform(die_a, die_b);
    return 0;
}
