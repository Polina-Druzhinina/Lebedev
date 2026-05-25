#pragma once
#include "shape.h"
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct ShapeCounts {
    int rectangles = 0;
    int circles = 0;
    int triangles = 0;
    int noise = 0;
};

class classifyShapes{
private:
    bool grid[200][200];
    bool visited[200][200];

    void resetGrid();
    void resetVisited();
    std::vector<Point> collectConnectedPixels(int startX, int startY);
    void calculateShapeFeatures(const vector<Point>& pixels,int& area, int& perimeter,double& compactness, double& solidity);
    string detectShapeType(int area, double compactness, double solidity);

public:
    classifyShapes();
    bool loadGridFromFile(const string& filename);
    ShapeCounts countShapes();
    void saveCountsToFile(const string& filename, const ShapeCounts& res);
};
