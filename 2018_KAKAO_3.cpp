#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string, int> city;
    map<int, string> sort_city;
    for (int i = 0; i < cities.size(); i++) {
        string c = cities[i];
        //모두 소문자로 바꿔주기
        for (int j = 0; j < c.length(); j++)
            if (c[j] < 'a') c[j] += 32;
        //처음에 cacheSize보다 작은 상황에서 무조건 입력들어갈때
        int key_num = -1;
        //해당 키값이 있다면?
        if (city.find(c) != city.end()) {
            answer += 1;
            key_num = city.find(c)->second;
            city.find(c)->second = i;
            sort_city.erase(key_num);
            sort_city.emplace(i, c);
        }
        //해당 키 값이 없다면?
        else {
            answer += 5;
            sort_city.emplace(i, c);
            city.emplace(c, i);
            if (city.size() > cacheSize) {
                auto kk = sort_city.begin();
                string key_string = kk->second;
                key_num = kk->first;
                city.erase(key_string);
                sort_city.erase(key_num);
            }
        }
    }
    return answer;
}
