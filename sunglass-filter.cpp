#include "sunglass-filter.h"

#include <iostream>
#include <opencv2/opencv.hpp>
#include <utility>

using namespace cv;

namespace sunglassfilter {
SunglassFilter::SunglassFilter(std::string face_path, std::string sunglass_path) {
    face = imread(face_path);
    sunglass = imread(sunglass_path);
}

std::pair<Bound, Bound> SunglassFilter::GetCoordinates(Mat &sunglass_img) {
    Bound row_index_bound;
    Bound col_index_bound;

    row_index_bound.first = 160;
    col_index_bound.first = 480;

    row_index_bound.second = row_index_bound.first + sunglass_img.size().height;
    col_index_bound.second = col_index_bound.first + sunglass_img.size().width;

    return std::make_pair(row_index_bound, col_index_bound);
}

void SunglassFilter::NaiveReplace() {
    Mat musk_with_naive_replace = face.clone();
    auto coordinates_bounds = GetCoordinates(sunglass);
    auto row_bounds = coordinates_bounds.first;
    auto col_bounds = coordinates_bounds.second;
    Mat roi_face = musk_with_naive_replace(Range(row_bounds.first, row_bounds.second),
                                           Range(col_bounds.first, col_bounds.second));
    // sunglass.copyTo(roi_face);
    imshow("naive", roi_face);
    waitKey(0);
}
}  // namespace sunglassfilter

int main() {
    std::string face_image_path = "../musk.png";
    std::string sun_glass_path = "../images/sunglass.png";
    Mat temp = imread(face_image_path);
    imshow("tempwi", temp);
    waitKey(0);
    // sunglassfilter::SunglassFilter sunglass_filter{face_image_path, sun_glass_path};
    // sunglass_filter.NaiveReplace();
    return 0;
}
