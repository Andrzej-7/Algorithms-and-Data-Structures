#include <iostream>
#include <vector>

using namespace std;

int minSum = 999;

bool canPlace(int n, int row, int col, vector<vector<int>> &board) {
    // check if you can place element on current column, left & right diagonals
    /*

     # * * *
     * * - -
     * - * -
     * - - *

     */
    // column
    for (int k = 0; k < row; k++) {
        if (board[k][col] > 0)
            return false;
    }

    int i, j;
    // left Diag
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] > 0)
            return false;

    // right diag
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] > 0)
            return false;

    return true;
}

void NQueen(int n, int row, int sum, vector<int> &result, vector<vector<int>> &board,
            vector<vector<int>> &values) {
    // base case - all elements have been placed, because it's last row
    if (row == n) {
        // update MIN sum if NEW sum is smaller
        if (sum <= minSum) {
            minSum = sum;
            // iterate through board and find all placed elements and add their columns to print result
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 1) {
                        result[i] = j;
                        break;
                    }
                }
            }
        }
        return;
    }

    // recursive case - place elements
    for (int col = 0; col < n; col++) {
        // if sum + current value already exceeds minSum - don't run recursion and skip to the next element
        if (sum + values[row][col] < minSum) {
            // check if it is possible to place element
            if (canPlace(n, row, col, board)) {
                board[row][col]++; // mark as visited
                NQueen(n, row + 1, sum + values[row][col], result, board, values); // update depth/row on each recursion
                board[row][col]--; // unmark and backtrack if unsuccessful
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> result(n); // print result
    vector<vector<int>> values; // cost of each element
    vector<vector<int>> board(n, vector<int>(n, 0)); // visited/unvisited

    int value;
    for (int i = 0; i < n; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            cin >> value;
            v.push_back(value);
        }
        values.push_back(v);
    }

    NQueen(n, 0, 0, result, board, values);

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    return 0;
}