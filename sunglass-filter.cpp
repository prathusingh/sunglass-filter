#include <iostream>
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

static void GetCoordinates(Mat &sunglass_img)
{
}

int main()
{
  // Load face image
  std::string face_image_path = "../musk.png";
  std::string sun_glass_path = "../sunglass.png";
  SunglassFilter sunglass_filter{face_image_path, sun_glass_path};
}

} // namespace sunglassfilter
