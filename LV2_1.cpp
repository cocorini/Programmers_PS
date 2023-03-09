#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

int solution(int n) {
    bitset<20> n1=n, ans=0;
    bool flag=false;
    int idx, cnt=0;
    for(int i=0;i<20;i++){
        if(!flag&&n1[i]) flag=true;
        else if(flag&&!n1[i]) {
            idx=i;
            break;
        }
        else if(flag&&n1[i]) cnt++;
    }
    ans[idx]=true;
    for(int i=0;i<cnt;i++) ans[i]=true;
    for(int i=19;i>idx;i--) ans[i]=n1[i];
    int answer = ans.to_ulong();
    return answer;
}
