class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>>& board) {
        return i>=0 && i<board.size() && j>=0 && j<board[0].size();
    }

    bool f(int i, int j, int index, vector<vector<char>>& board, string word) {
        // base case
        if(index >= word.size()) {
            return true;
        }
        if(!isValid(i, j, board)) {
            return false;
        }
        if(board[i][j] != word[index]) {
            return false;
        }

        // transition
        char ch = board[i][j];
        board[i][j] = '#'; // prevent from comming back
        bool right = f(i, j+1, index+1, board, word);
        bool down = f(i+1, j, index+1, board, word);
        bool left = f(i, j-1, index+1, board, word);
        bool up = f(i-1, j, index+1, board, word);
        board[i][j] = ch;

        // ans
        bool ans = right || down || left || up;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(f(i, j, 0, board, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};