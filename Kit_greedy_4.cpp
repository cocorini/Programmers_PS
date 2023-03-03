#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<>());
    int last_idx=people.size()-1;
    for(int i=0;i<people.size();i++){
        if(last_idx<i) break;
        if(people[i]+people[last_idx]<=limit){
            last_idx--;
            answer++;
        }
        else answer++;
    }
    return answer;
}
