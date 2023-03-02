#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
void solve();
vector<string> record, answer;
vector<pair<string,string>> ans;
map<string,string> users;
vector<string> solution(vector<string> records) {
    record=records;
    solve();
    return answer;
}
void solve(){
    for(int i=0;i<record.size();i++){
        vector<int> nullp;
        for(int j=0;j<record[i].size();j++){
            if(record[i][j]==' ') nullp.push_back(j);
        }
        string user_id, user_nick;
        if(record[i][0]=='E'||record[i][0]=='C') {
            user_id=record[i].substr(nullp[0]+1, nullp[1]-nullp[0]-1);
            user_nick=record[i].substr(nullp[1]+1, record[i].length()-nullp[1]-1);
            if(record[i][0]=='E'){
                users.emplace(user_id, user_nick);
                if(users.find(user_id)==users.end()) ans.emplace_back(user_id, "님이 들어왔습니다.");
                else {
                    ans.emplace_back(user_id, "님이 들어왔습니다.");
                    users.find(user_id)->second=user_nick;
                }
            }
            else{
                users.find(user_id)->second=user_nick;
            }
        }
        else {
            user_id=record[i].substr(nullp[0]+1, record[i].length()-nullp[0]-1);
            ans.emplace_back(user_id, "님이 나갔습니다.");
        }   
    }
    for(int i=0;i<ans.size();i++){
        string s="";
        s+=users.find(ans[i].first)->second;
        s+=ans[i].second;
        answer.push_back(s);
    }
}
