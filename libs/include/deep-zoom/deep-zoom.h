#pragma once

#include <complex>
#include <vector>

namespace zoomer
{

struct Image
{
    Image(int width, int height);
    ~Image() = default;

    int width() const
    {
        return m_width;
    }
    int height() const
    {
        return m_height;
    }

    int get(int x, int y) const;
    void plot(int x, int y, int iter);

private:
    int m_width;
    int m_height;
    std::vector<int> m_iterations;
};

using Complex = std::complex<double>;

Image plot(Complex center, double magnification, int width, int height);

} // namespace zoomer
