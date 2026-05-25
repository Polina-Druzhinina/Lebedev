#include <queue>
#include <algorithm>
#include "volna.h"

bool Volna::hasPath() const {
    return found;
}

const vector<pair<int,int>>& Volna::getPath() const {
    return path;
}

bool Volna::isWall(const Image& img, int x, int y) const {
    if (x < 0 || x >= img.getWidth() || y < 0 || y >= img.getHeight())
        return true;
    cv::Vec3b p = img.getImage().at<cv::Vec3b>(y, x);
    return p[0] == 0 && p[1] == 0 && p[2] == 0;
}

void Volna::findPath(const Image& img) {
    found = false;

    int w = img.getWidth(), h = img.getHeight();
    int sx = img.getStartX(), sy = img.getStartY();
    int gx = img.getGoalX(), gy = img.getGoalY();

    const int INF = 1e9;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    queue<pair<int,int>> q;

    dist[sy][sx] = 0;
    q.push(make_pair(sx, sy));

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        int d = dist[y][x];

        if (x == gx && y == gy) break;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (isWall(img, nx, ny)) continue;
            if (dist[ny][nx] != INF) continue;

            dist[ny][nx] = d + 1;
            q.push(make_pair(nx, ny));
        }
    }

    if (dist[gy][gx] == INF) return;

    found = true;

    vector<pair<int,int>> result;
    int x = gx, y = gy;
    while (x != sx || y != sy) {
        result.push_back(make_pair(x, y));
        int d = dist[y][x];
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (isWall(img, nx, ny)) continue;
            if (dist[ny][nx] == d - 1) {
                x = nx;
                y = ny;
                break;
            }
        }
    }
    result.push_back(make_pair(sx, sy));
    reverse(result.begin(), result.end());
    path = result;
}
