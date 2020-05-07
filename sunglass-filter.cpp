#include <iostream>
#include <utility>

#include <opencv2/opencv.hpp>

#include "sunglass-filter.h";

using namespace cv;

namespace sunglassfilter
{
SunglassFilter::SunglassFilter(std::string facePath, std::string sunglassPath)
    : face(imread(facePath), sunglass(imread(sunglassPath))) {}

void SunglassFilter::NaiveReplace(Mat &face_img, Mat &sunglass_img)
{
  std::cout << "naive replace" << std::endl;
}

void SunglassFilter::UsingMask(Mat &face_img, Mat &sunglass_img, Mat &alpha_mask)
{
  std::cout << "using mask" << std::endl;
}

std::pair<std::pair<int, int>, std::pair<int, int>> SunglassFilter::GetCoordinates(Mat &sunglass_img)
{
  Bound row_index_bound;
  Bound col_index_bound;

  row_index_bound.first = 160;
  col_index_bound.first = 480;

  row_index_bound.second = row_index_bound.first + sunglass_img.size().height;
  col_index_bound.second = col_index_bound.first + sunglass_img.size().width;

  return std::make_pair(row_index_bound, col_index_bound);
}

int main()
{
  std::string face_image_path = "../images/musk.png";
  std::string sun_glass_path = "../images/sunglass.png";
  SunglassFilter sunglass_filter{face_image_path, sun_glass_path};
}
} // namespace sunglassfilter
