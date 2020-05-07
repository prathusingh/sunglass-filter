#ifndef SUNGLASS_FILTER_H_
#define SUNGLASS_FILTER_H_

#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;

namespace sunglassfilter
{
class SunglassFilter
{
private:
    Mat face;
    Mat sunglass;

public:
    SunglassFilter(std::string face_path, std::string sunglass_path);

    void NaiveReplace(Mat &face_img, Mat &sunglass_img);

    void UsingMask(Mat &face_img, Mat &sunglass_img, Mat &alpha_mask);

    static void GetCoordinates(Mat &sunglass_img);
};
} // namespace sunglassfilter

#endif // SUNGLASS_FILTER_H_