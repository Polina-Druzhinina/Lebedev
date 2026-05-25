#include "classifyShapes.h"

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

classifyShapes::classifyShapes() {
    resetGrid();
    resetVisited();
}

void classifyShapes::resetGrid() {
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            grid[i][j] = false;
        }
    }
}

void classifyShapes::resetVisited() {
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            visited[i][j] = false;
        }
    }
}

vector<Point> classifyShapes::collectConnectedPixels(int startX, int startY) {
    vector<Point> pixels;
    queue<Point> q;

    visited[startY][startX] = true;

    Point start;
    start.x = startX;
    start.y = startY;
    q.push(start);

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        pixels.push_back(cur);

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && nx < 200 && ny >= 0 && ny < 200 &&
                grid[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = true;

                Point next;
                next.x = nx;
                next.y = ny;
                q.push(next);
            }
        }
    }
    return pixels;
};

void classifyShapes::calculateShapeFeatures(const vector<Point>& pixels,int& area, int& perimeter, double& compactness, double& solidity) {
    area = pixels.size();
    if (area == 0) return;

    int minX = 200, maxX = 0, minY = 200, maxY = 0;
    for (int i = 0; i < area; i++) {
        if (pixels[i].x < minX) minX = pixels[i].x;
        if (pixels[i].x > maxX) maxX = pixels[i].x;
        if (pixels[i].y < minY) minY = pixels[i].y;
        if (pixels[i].y > maxY) maxY = pixels[i].y;
    }

    perimeter = 0;
    int dx4[4] = {-1, 1, 0, 0};
    int dy4[4] = {0, 0, -1, 1};
    for (int i = 0; i < area; i++) {
        for (int d = 0; d < 4; d++) {
            int nx = pixels[i].x + dx4[d];
            int ny = pixels[i].y + dy4[d];
            if (nx < 0 || nx >= 200 || ny < 0 || ny >= 200 || !grid[ny][nx]) {
                perimeter++;
            }
        }
    }

    int bboxArea = (maxX - minX + 1) * (maxY - minY + 1);
    solidity = (bboxArea > 0) ? (double)area / bboxArea : 0.0;
    compactness = (perimeter > 0) ? (4.0 * 3.14159 * area) / (perimeter * perimeter) : 0.0;
}

string classifyShapes::detectShapeType(int area, double compactness, double solidity) {
    if (area < 15) return "Noise";

    if (solidity > 0.92) return "Rectangle";
    if (compactness > 0.52 && solidity > 0.65) return "Circle";
    if (solidity > 0.30) return "Triangle";

    return "Noise";
}

bool classifyShapes::loadGridFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Ошибка: файл " << filename << " не найден!" << endl;
        return false;
    }

    resetVisited();
    resetGrid();
    string line;
    for (int y = 0; y < 200; y++) {
        fin >> line;
        if (line.length() != 200) {
            return false;
        }
        for (int x = 0; x < 200; x++) {
            grid[y][x] = (line[x] == '1');
        }
    }
    fin.close();
    return true;
}

ShapeCounts classifyShapes::countShapes() {
    ShapeCounts res;
    for (int y = 0; y < 200; y++) {
        for (int x = 0; x < 200; x++) {
            if (grid[y][x] && !visited[y][x]) {
                vector<Point> component = collectConnectedPixels(x, y);

                int area, perimeter;
                double compactness, solidity;
                calculateShapeFeatures(component, area, perimeter, compactness, solidity);

                string type = detectShapeType(area, compactness, solidity);
                if (type == "Rectangle") res.rectangles++;
                else if (type == "Circle") res.circles++;
                else if (type == "Triangle") res.triangles++;
                else res.noise++;
            }
        }
    }
    return res;
}

void classifyShapes::saveCountsToFile(const string& filename, const ShapeCounts& res) {
    ofstream fout(filename);
    fout << "Rectangle = " << res.rectangles <<endl;
    fout << "Circle = " << res.circles <<endl;
    fout << "Triangle = " << res.triangles <<endl;
    fout << "Noise = " << res.noise << endl;
    fout.close();
}
