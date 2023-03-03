#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(int i=k;i<number.length();i++) answer+=number[i];
    for(int i=k-1;i>=0;i--){
        //answer[0]이랑 비교
        if(number[i]>=answer[0]){
            int tmp=answer[0];
            answer[0]=number[i];
            number[i]=tmp;
            for(int j=1;j<answer.length();j++){
                if(number[i]>=answer[j]){
                    tmp=answer[j];
                    answer[j]=number[i];
                    number[i]=tmp;
                }
                else break;
            }
        }
    }
    return answer;
}
