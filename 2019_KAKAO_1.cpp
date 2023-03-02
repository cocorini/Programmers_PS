#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> stage, ans;
void solve();
int N;
vector<int> solution(int n, vector<int> stages) {
    stage=stages;
    N=n;
    solve();
    return ans;
}
void solve(){
    vector<pair<double, int>> stage_fail;
    for(int i=1;i<=N;i++){
        double mo=0, ja=0;
        for(int j=0;j<stage.size();j++){
            if(stage[j]>=i) mo++;
            if(stage[j]==i) ja++;
        }
        if(!mo) stage_fail.emplace_back(0,-i);
        else stage_fail.emplace_back(ja/mo,-i);
    }
    sort(stage_fail.begin(), stage_fail.end(), greater<>());
    for(int i=0;i<stage_fail.size();i++){
        stage_fail[i].second*=-1;
        ans.push_back(stage_fail[i].second);
    }
}
