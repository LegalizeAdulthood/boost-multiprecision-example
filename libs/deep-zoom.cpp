#include "deep-zoom/deep-zoom.h"

namespace zoomer
{

Image::Image(int width, int height) :
    m_width(width),
    m_height(height),
    m_iterations(width * height)
{
}

int Image::get(int x, int y) const
{
    return m_iterations[y * m_width + x];
}

void Image::plot(int x, int y, int iter)
{
    m_iterations[y * m_width + x] = iter;
}

static bool bailout(const Complex &z)
{
    return std::norm(z) > 4.0;
}

static Complex formula(Complex z, const Complex &c)
{
    z *= z;
    z += c;
    return z;
}

Image plot(Complex center, double magnification, int width, int height)
{
    Image result{width, height};
    const double left{center.real() - magnification / 2.0};
    const double bottom{center.imag() - magnification / 2.0};
    const double dr{magnification / static_cast<double>(width)};
    const double di{magnification / static_cast<double>(height)};

    double im{bottom};
    for (int y = 0; y < height; ++y)
    {
        double re{left};
        for (int x = 0; x < width; ++x)
        {
            const Complex c{re, im};
            Complex z{c};
            int i;
            for (i = 1; i < 256; ++i)
            {
                if (bailout(z))
                {
                    break;
                }
                z = formula(z, c);
            }
            result.plot(x, y, i);
            re += dr;
        }
        im += di;
    }

    return result;
}

} // namespace zoomer
