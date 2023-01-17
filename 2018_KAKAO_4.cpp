#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int m, int n, vector<string> board) {vector<vector<bool>> visited(m, vector<bool>(n, false));
    int answer = 0;
    bool loof = false;
    while (1) {
        loof = false;
        for (int i = 0; i < board.size() - 1; i++) {
            for (int j = 0; j < board[i].size() - 1; j++) {
                char c = board[i][j];
                if (c != '0') {
                    if (board[i + 1][j] == c && board[i + 1][j + 1] == c && board[i][j + 1] == c) {
                        for (int k = 0; k < 2; k++)
                            for (int kk = 0; kk < 2; kk++) {
                                visited[i + k][j + kk] = true;
                                loof = true;
                            }
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (visited[i][j]) {
                    board[i][j] = '0';
                    visited[i][j] = false;
                    answer++;
                }
        for (int j = 0; j < n; j++) {
            priority_queue <pair<int,char>> q;
            for (int i = m - 1; i >= 0; i--) {
                char c = board[i][j];
                if (c == '0') q.emplace(10000, '0');
                else q.emplace(m - i, c);
            }
            int i = 0;
            while (!q.empty()) {
                board[i][j] = q.top().second;
                q.pop();
                i++;
            }
        }
        if (!loof) break;
    }
    return answer;
}
