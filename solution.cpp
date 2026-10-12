#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int max_fish = 0;
    
    // Directions: up, down, left, right
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                // Start BFS for this connected component
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                int current_fish = 0;
                
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    current_fish += grid[x][y];
                    
                    // Check all 4 neighbors
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                            grid[nx][ny] > 0 && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                
                max_fish = max(max_fish, current_fish);
            }
        }
    }
    
    cout << max_fish << endl;
    return 0;
}