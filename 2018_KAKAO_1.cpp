#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> stage_score(4, 0);
int solution(string dartResult) {
    int answer = 0;
    for (int i = 0, stage = 1; i < dartResult.length(); i++) {
        if (dartResult[i] <= '9' && dartResult[i] >= '0') {
            if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
                stage_score[stage] = 10;
                i++;
                continue;
            }
            else stage_score[stage] = dartResult[i] - '0';
        }
        else if (dartResult[i] == 'D') {
            stage_score[stage] = pow(stage_score[stage], 2);
            stage++;
        }
        else if (dartResult[i] == 'T') {
            stage_score[stage] = pow(stage_score[stage], 3);
            stage++;
        }
        else if (dartResult[i] == 'S') {
            stage++;
            continue;
        }
        else if (dartResult[i] == '*' || dartResult[i] == '#') {
            stage--;
            if (dartResult[i] == '*') {
                if (stage == 1) stage_score[stage] *= 2;
                else {
                    stage_score[--stage] *= 2;
                    stage_score[++stage] *= 2;
                }
            }
            else stage_score[stage] *= -1;
            stage++;
        }

    }
    for (int i = 1; i <= 3; i++) answer += stage_score[i];
    return answer;
}
