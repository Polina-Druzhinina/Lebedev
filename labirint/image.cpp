#include "image.h"

bool Image::loadImage(const string& filename) {
    img = cv::imread(filename);
    if (img.empty()) return false;

    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            cv::Vec3b p = img.at<cv::Vec3b>(y, x);
            if (p[2] > 200 && p[1] < 50 && p[0] < 50) {
                cx = x; cy = y;
            }
            if (p[1] > 150 && p[2] < 100 && p[0] < 100) {
                gx = x; gy = y;
            }
        }
    }
    return true;
}

int Image::getStartX() const { return cx; }
int Image::getStartY() const { return cy; }
int Image::getGoalX() const { return gx; }
int Image::getGoalY() const { return gy; }
int Image::getWidth() const { return img.cols; }
int Image::getHeight() const { return img.rows; }
const cv::Mat& Image::getImage() const { return img; }
