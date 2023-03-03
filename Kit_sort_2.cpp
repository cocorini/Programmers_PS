#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve();
bool cmp(const string &a, const string &b){
    return a + b > b + a;
}
vector<int> num;
string answer = "";
string solution(vector<int> numbers) {
    num=numbers;
    solve();
    return answer;
}
void solve(){
    vector<string> nums;
    for(int i=0;i<num.size();i++){
        nums.push_back(to_string(num[i]));
    }
    sort(nums.begin(), nums.end(), cmp);
    for(int i=0;i<nums.size();i++) answer+=nums[i];
    if(answer[0]=='0') answer="0";
}
