#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
  cv::Mat src1;
  cv::Mat src2;
  if (argc == 2) {
    cv::Mat src = cv::imread(argv[1]);

    if (src.empty()) {
      printf("wrong image");
      return -1;
    }

    cv::Rect rect1;
    cv::Rect rect2;
    if (src.size().width > src.size().height) {
      rect1 = cv::Rect(0,
                       0,
                       src.size().width / 2.0,
                       src.size().height);
      rect2 = cv::Rect(src.size().width / 2.0,
                       0,
                       src.size().width / 2.0,
                       src.size().height);
    } else {
      rect1 = cv::Rect(0,
                       0,
                       src.size().width,
                       src.size().height / 2.0);
      rect2 = cv::Rect(0,
                       src.size().height / 2.0,
                       src.size().width,
                       src.size().height / 2.0);
    }

    src1 = src(rect1);
    src2 = src(rect2);

    if (src1.empty() || src2.empty()) {
      printf("wrong image");
      return -1;
    }

    if (src1.size() != src2.size()) {
      printf("wrong image");
      return -1;
    }

  } else if (argc == 3) {
    src1 = cv::imread(argv[1]);
    src2 = cv::imread(argv[2]);

    if (src1.empty() || src2.empty()) {
      printf("wrong image");
      return -1;
    }
  } else {
    printf("./machigaisagashi IMAGE_PATH");
    printf("or");
    printf("./machigaisagashi  IMAGE_PATH1  IMAGE_PATH2");
    return -1;
  }

  cv::Mat dst;

  cv::absdiff(src1, src2, dst);
  cv::cvtColor(dst, dst, CV_BGR2GRAY);
  cv::threshold(dst, dst, 50, 255, cv::THRESH_BINARY);

  std::vector<std::vector<cv::Point>> contours;
  cv::findContours(dst, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
  dst = src1.clone();
  for (auto contour = contours.begin(); contour != contours.end(); contour++){
    cv::polylines(dst, *contour, true, cv::Scalar(0, 255, 0), 2);
  }

  std::string filename = argv[1];
  filename += ".png";
  cv::imwrite(filename, dst);

  return 0;
}
