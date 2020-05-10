#ifndef SUNGLASS_FILTER_H_
#define SUNGLASS_FILTER_H_

#include <opencv2/opencv.hpp>
#include <string>
#include <utility>

using namespace cv;

namespace sunglassfilter {
typedef std::pair<int, int> Bound;

class SunglassFilter {
   private:
    Mat face;
    Mat sunglass;

   public:
    SunglassFilter(std::string face_path, std::string sunglass_path);

    void NaiveReplace();

    void UsingMask(Mat &face_img, Mat &sunglass_img, Mat &alpha_mask);

    static std::pair<Bound, Bound> GetCoordinates(Mat &sunglass_img);
};
}  // namespace sunglassfilter

#endif  // SUNGLASS_FILTER_H_