class Solution {
public:

    bool isSafe(vector<string> &board, int row, int col, int n) {
        // Check same column
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        int i = row - 1;
        int j = col - 1;
        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q') return false;
            i--; j--;
        }

        // Check upper-right diagonal
        i = row - 1;
        j = col + 1;
        while(i >= 0 && j < n) {
            if(board[i][j] == 'Q') return false;
            i--; j++;
        }

        return true;
    }

    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++) {
            if(isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueens(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);
        return ans;
    }
};
