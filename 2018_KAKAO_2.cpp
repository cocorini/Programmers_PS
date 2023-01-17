#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<int> A = arr1, B = arr2;
    vector<string> answer;
    vector<string> v1(n, ""), v2(n, "");
    //이진법으로 나타내기
    for (int i = n - 1; i >= 0; i--) {
        int val = pow(2, i);
        for (int j = 0; j < n; j++) {
            if (val > A[j]) {
                v1[j] += '0';
                continue;
            }
            else {
                if (val == A[j]) {
                    v1[j] += '1';
                    A[j] = 0;
                }
                else {
                    v1[j] += '1';
                    A[j] -= val;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (val > B[j]) {
                v2[j] += '0';
                continue;
            }
            else {
                if (val == B[j]) {
                    v2[j] += '1';
                    B[j] = 0;
                }
                else {
                    v2[j] += '1';
                    B[j] -= val;
                }
            }
        }
    }
    //해독하기
    for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < n; j++) {
            if (v1[i][j] == '1' || v2[i][j] == '1') s += '#';
            else s += ' ';
        }
        answer.push_back(s);
    }
    return answer;
}
