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
    Mat alpha_mask;
    Mat sunglass_RGB;

   public:
    SunglassFilter(std::string face_path, std::string sunglass_path);

    void SplitSunglassIntoChannels();

    std::pair<Bound, Bound> GetCoordinates();

    void NaiveReplace();

    void UsingMask();
};
}  // namespace sunglassfilter

#endif  // SUNGLASS_FILTER_H_