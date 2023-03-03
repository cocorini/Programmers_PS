#include<vector>
#include <queue>
using namespace std;
int bfs();
int N, M;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
vector<vector<int>> visited, map;
int solution(vector<vector<int>> maps) {
    N=maps.size();
    M=maps[0].size();
    visited.assign(N, vector<int>(M, -1));
    map=maps;
    int answer = bfs();
    return answer;
}
int bfs(){
    queue<pair<int,int>> q;
    q.emplace(0, 0);
    visited[0][0]=1;
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        int cnt=visited[y][x];
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(ny>=0&&nx>=0&&ny<N&&nx<M){
                if(visited[ny][nx]<0&&map[ny][nx]>0){
                    visited[ny][nx]=cnt+1;
                    if(ny==N-1&&nx==M-1){
                        return visited[ny][nx];
                    }
                    q.emplace(ny, nx);
                }
            }
        }
    }
    return -1;
}
