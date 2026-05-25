#pragma once
#include <string>
#include <opencv2/opencv.hpp>
using namespace std;

class Image {
public:
    bool loadImage(const string& filename);
    int getStartX() const;
    int getStartY() const;
    int getGoalX() const;
    int getGoalY() const;
    int getWidth() const;
    int getHeight() const;
    const cv::Mat& getImage() const;

private:
    cv::Mat img;
    int cx = 0, cy = 0;
    int gx = 0, gy = 0;
};
