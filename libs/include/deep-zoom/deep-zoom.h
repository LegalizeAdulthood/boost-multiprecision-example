#pragma once

#include <complex>

namespace zoomer
{

struct Image
{
};

Image plot(std::complex<double> center, double magnification, int width, int height);

};
