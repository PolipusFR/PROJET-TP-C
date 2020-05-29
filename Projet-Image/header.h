#pragma once
#include "pch.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Mat FiltreMedian(Mat image);

Mat FiltreGauss(Mat image);

Mat FiltreSobel(Mat image);

Mat DilaEro();

Mat FiltreDilatation(Mat image);

Mat FiltreErosion(Mat image);

Mat FiltreCanny(Mat image);

Mat FiltreSeuil(Mat image);

void affResult(Mat image, std::string windowName);