#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll solution(int n, vector<int> times) {
    ll ans=0;
    sort(times.begin(), times.end(), greater<>());
    ll left=0, right=times[0]*n;
    while(left<=right){
        ll man=0, mid=(left+right)/2;
        for(int i=0;i<times.size();i++) man+=mid/(ll)times[i];
        if(man>=n){
            right=mid-1;
            ans=mid;
        }
        else left=mid+1;
    }
    return ans;
}
