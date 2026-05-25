#pragma once
#include <opencv2/opencv.hpp>
#include "Volna.h"

class Drawer {
public:
    void drawPath(const Image& img, const Volna& volna);
    void show() const;
    void save(const string& filename) const;

private:
    cv::Mat canvas;
};
