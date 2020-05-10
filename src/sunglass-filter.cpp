#include "sunglass-filter.h"

#include <iostream>
#include <opencv2/opencv.hpp>
#include <utility>

//#include "boost/filesystem.hpp"

using namespace cv;

namespace sunglassfilter {
SunglassFilter::SunglassFilter(std::string face_path, std::string sunglass_path) {
    face = imread(face_path);
    sunglass = imread(sunglass_path, -1);
    resize(sunglass, sunglass, Size(), 0.4, 0.4);
}

void SunglassFilter::SplitSunglassIntoChannels() {
    // Separate the color and alpha channels
    Mat glass_RGBA_channels[4];
    Mat glass_RGB_channels[3];

    split(sunglass, glass_RGBA_channels);
    for (int i = 0; i < 3; i++) {
        glass_RGB_channels[i] = glass_RGBA_channels[i];
    }

    merge(glass_RGB_channels, 3, sunglass_RGB);

    // alpha mask is the fourth channel
    alpha_mask = glass_RGBA_channels[3];
}

std::pair<Bound, Bound> SunglassFilter::GetCoordinates() {
    Bound row_index_bound;
    Bound col_index_bound;

    row_index_bound.first = 160;
    col_index_bound.first = 480;

    row_index_bound.second = row_index_bound.first + sunglass.size().height;
    col_index_bound.second = col_index_bound.first + sunglass.size().width;

    return std::make_pair(row_index_bound, col_index_bound);
}

void SunglassFilter::NaiveReplace() {
    Mat musk_with_naive_replace = face.clone();
    auto coordinates_bounds = GetCoordinates();
    auto row_bounds = coordinates_bounds.first;
    auto col_bounds = coordinates_bounds.second;
    Mat roi_face = musk_with_naive_replace(Range(row_bounds.first, row_bounds.second),
                                           Range(col_bounds.first, col_bounds.second));
    sunglass_RGB.copyTo(roi_face);
    imshow("naive", musk_with_naive_replace);
    waitKey(0);
}

}  // namespace sunglassfilter

int main() {
    std::string face_image_path = "./src/images/musk.png";
    std::string sun_glass_path = "./src/images/sunglass.png";
    sunglassfilter::SunglassFilter sunglass_filter{face_image_path, sun_glass_path};
    sunglass_filter.SplitSunglassIntoChannels();
    sunglass_filter.NaiveReplace();
    return 0;
}
