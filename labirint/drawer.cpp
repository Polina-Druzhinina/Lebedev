#include "drawer.h"

void Drawer::drawPath(const Image& img, const Volna& volna) {
    canvas = img.getImage().clone();

    if (!volna.hasPath()) return;

    const vector<pair<int,int>>& path = volna.getPath();
    for (int i = 0; i < (int)path.size(); i++) {
        int x = path[i].first;
        int y = path[i].second;
        cv::circle(canvas, cv::Point(x, y), 1, cv::Scalar(255, 0, 0), -1);
    }

    cv::circle(canvas, cv::Point(img.getStartX(), img.getStartY()), 3, cv::Scalar(0, 0, 255), -1);
    cv::circle(canvas, cv::Point(img.getGoalX(), img.getGoalY()), 3, cv::Scalar(0, 255, 0), -1);
}

void Drawer::show() const {
    cv::imshow("Labirint", canvas);
    cv::waitKey(0);
}

void Drawer::save(const string& filename) const {
    cv::imwrite(filename, canvas);
}
