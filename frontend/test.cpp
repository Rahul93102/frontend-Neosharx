#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <random>
#include <chrono>

using namespace std;

// This is the optimal solution using Dynamic Programming.
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
// where n is the length of the dataset string.
// This approach is correct based on the problem's recursive structure,
// but it might be too slow if the constraints are as high as 10^5.
// For typical competitive programming constraints (n <= 500), this is the standard solution.

int minimizeCleaningCost(string dataset, int matchCost, int mismatchCost) {
    int n = dataset.length();
    if (n == 0) {
        return 0;
    }
    if (n % 2 != 0) {
        // This case should not happen based on constraints, but as a safeguard:
        return -1; // Or handle as an error
    }

    // dp[i][j] stores the minimum cost to clean the substring from index i to j.
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Iterate over all possible substring lengths (must be even).
    for (int len = 2; len <= n; len += 2) {
        // Iterate over all possible starting indices for substrings of the current length.
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;

            // --- Option 1: Pair the outer characters s[i] and s[j] ---
            int cost_outer_pair = (dataset[i] == dataset[j]) ? matchCost : mismatchCost;
            int current_cost = cost_outer_pair + dp[i + 1][j - 1];

            // --- Option 2: Split the substring into two smaller, valid subproblems ---
            // Find the minimum cost by splitting s[i..j] into s[i..k] and s[k+1..j].
            // The split must happen at an odd index `k` to ensure both substrings
            // have even length.
            for (int k = i + 1; k < j; k += 2) {
                current_cost = min(current_cost, dp[i][k] + dp[k + 1][j]);
            }
            dp[i][j] = current_cost;
        }
    }

    return dp[0][n - 1];
}


// --- Test Harness ---

// Brute-force recursive solution for verification on small inputs.
int solve_brute_force(string dataset, int matchCost, int mismatchCost) {
    int n = dataset.length();
    if (n == 0) {
        return 0;
    }
    if (n % 2 != 0) {
        return INT_MAX;
    }

    int min_cost = INT_MAX;

    // Iterate through all possible pairs to remove
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string next_dataset = "";
            for (int k = 0; k < n; ++k) {
                if (k != i && k != j) {
                    next_dataset += dataset[k];
                }
            }
            int current_pair_cost = (dataset[i] == dataset[j]) ? matchCost : mismatchCost;
            int future_cost = solve_brute_force(next_dataset, matchCost, mismatchCost);

            if (future_cost != INT_MAX) {
                min_cost = min(min_cost, current_pair_cost + future_cost);
            }
        }
    }
    return min_cost;
}

void print_input(const string& dataset, int matchCost, int mismatchCost) {
    cout << "Input:\n";
    cout << "  dataset = \"" << dataset << "\"\n";
    cout << "  matchCost = " << matchCost << ", mismatchCost = " << mismatchCost << "\n";
}

void run_test(int test_num, const string& dataset, int matchCost, int mismatchCost, int expected) {
    cout << "--- Static Test Case " << test_num << " ---\n";
    print_input(dataset, matchCost, mismatchCost);
    int result = minimizeCleaningCost(dataset, matchCost, mismatchCost);
    cout << "Output: " << result << "\n";
    cout << "Expected: " << expected << "\n";
    if (result == expected) {
        cout << "Status: PASS ✅\n\n";
    } else {
        cout << "Status: FAIL ❌\n\n";
    }
}

string generate_random_string(int len, mt19937& rng) {
    uniform_int_distribution<int> char_dist('a', 'd'); // Small alphabet for more matches
    string s = "";
    for(int i = 0; i < len; ++i) {
        s += char_dist(rng);
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // --- Provided Sample Cases ---
    run_test(1, "aaabca", 3, 2, 7);
    run_test(2, "xxch", 5, 5, 10);
    run_test(3, "ouio", 2, 4, 6);

    // --- Edge Cases ---
    run_test(4, "ab", 10, 1, 1);
    run_test(5, "aa", 10, 1, 10);
    run_test(6, "", 100, 100, 0);
    run_test(7, "abacaba", 1, 10, -1); // Odd length
    run_test(8, "zzzzzz", 1, 10, 3);

    // --- Cases where pairing outer is better ---
    run_test(9, "abccba", 1, 10, 3); // (a,a), (b,b), (c,c) -> 1+1+1 = 3
    run_test(10, "topcoderopen", 10, 1, 12); // (t,t) better than splitting

    // --- Cases where splitting is better ---
    run_test(11, "abacabaa", 10, 1, 13); // "abacab" + "aa"
    run_test(12, "aabb", 1, 10, 2); // "aa" + "bb" -> 1+1=2 vs (a,b) + "ab" -> 10+10=20
    run_test(13, "abracadabra", 5, 5, -1); // Odd
    run_test(14, "racecar", 1, 1, -1); // Odd
    run_test(15, "zyxw", 100, 1, 2);
    run_test(16, "abacabaabc", 1, 10, 30);

    // --- More complex cases ---
    run_test(17, "abcdefgh", 1, 1, 4);
    run_test(18, "agct", 100, 1, 2);
    run_test(19, "abac", 3, 8, 11); // "ab"+"ac" -> 8+8=16. (a,c)+"ba"->8+8=16. (a,a)+"bc"->3+8=11
    run_test(20, "topcoder", 10, 1, 4);
    run_test(21, "zzzaac", 3, 8, 14); //(z,z)+zaac -> 3 + dp[zaac]. dp[zaac] = min((z,c)+aa -> 8+3=11, (z,a)+ac->8+8=16) = 11. Total = 14
    run_test(22, "abacabad", 1, 100, 400); // Mismatches everywhere
    run_test(23, "aaaaaaaa", 1, 100, 4);
    run_test(24, "abracadabraa", 10, 1, 14); // Lots of splits and pairs
    run_test(25, "delete", 7, 8, 23); // (d,e)+elet -> 8 + dp[elet]. dp[elet] = min((e,t)+le -> 8+8=16, (e,l)+et->8+8=16) = 16. Total 24.  Split: (de)+(lete). (de)=8. (lete) = (l,e)+et -> 8+8=16. Total 24. Outer (d,e)+elet. elete->(e,e)+lt -> 7+8=15. Total 8+15=23.

    // --- Random Test Cases ---
    cout << "\n--- Starting Random Tests ---\n\n";
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int num_random_tests = 25;

    for (int i = 1; i <= num_random_tests; ++i) {
        uniform_int_distribution<int> len_dist(1, 7); // small even length for brute force
        int n = len_dist(rng) * 2;

        string dataset = generate_random_string(n, rng);

        uniform_int_distribution<int> cost_dist(1, 10);
        int matchCost = cost_dist(rng);
        int mismatchCost = cost_dist(rng);

        cout << "--- Random Test Case " << i << " ---\n";
        print_input(dataset, matchCost, mismatchCost);

        int dp_result = minimizeCleaningCost(dataset, matchCost, mismatchCost);
        int brute_result = solve_brute_force(dataset, matchCost, mismatchCost);

        cout << "DP Output: " << dp_result << "\n";
        cout << "Brute Force Output: " << brute_result << "\n";
        if (dp_result == brute_result) {
            cout << "Status: PASS ✅\n\n";
        } else {
            cout << "Status: FAIL ❌\n\n";
        }
    }

    return 0;
}