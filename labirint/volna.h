#pragma once
#include <vector>
#include "image.h"
using namespace std;

class Volna {
public:
    void findPath(const Image& img);
    bool hasPath() const;
    const vector<pair<int,int>>& getPath() const;

private:
    bool isWall(const Image& img, int x, int y) const;
    bool found = false;
    vector<pair<int,int>> path;
};
