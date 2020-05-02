#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void naiveReplace(Mat &muskImage, Mat &sunglassRGB)
{
    // using hit and trial find the top left and the top right
    // top left corner of the glasses
    int topLeftRow = 130;
    int topLeftCol = 130;

    int bottomRightRow = topLeftRow + sunglassRGB.size().height;
    int bottomRightCol = topLeftCol + sunglassRGB.size().width;

    Mat muskWithNaiveReplace = muskImage.clone();

    Mat roiFace = muskWithNaiveReplace(Range(topLeftRow, bottomRightRow), Range(topLeftCol, bottomRightCol));

    sunglassRGB.copyTo(roiFace);

    imshow("naive", muskWithNaiveReplace);
}

int main()
{
    // Load face image
    string faceImagePath = "../musk.png";
    Mat faceImage = imread(faceImagePath);

    string sunglassImagePath = "../sunglass.png";
    Mat sunglassImage = imread(sunglassImagePath, -1);

    resize(sunglassImage, sunglassImage, Size(), 0.4, 0.4);

    imshow("sunglass", sunglassImage);

    cout << "Sunglass Dimensions" << sunglassImage.size() << endl;
    cout << "Sunglass channels" << sunglassImage.channels();

    // Separate the color and alpha channels
    Mat glassRGBAChannels[4];
    Mat glassRGBChannels[3];

    split(sunglassImage, glassRGBAChannels);

    for (int i = 0; i < 3; i++)
    {
        glassRGBChannels[i] = glassRGBAChannels[i];
    }

    Mat sunglassRGBImage;

    merge(glassRGBChannels, 3, sunglassRGBImage);

    // alpha mask is the fourth channel
    Mat alphaMask = glassRGBAChannels[3];

    naiveReplace(faceImage, sunglassRGBImage);

    waitKey(0);
    return 0;
}