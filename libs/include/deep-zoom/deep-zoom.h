#pragma once

#include <boost/multiprecision/cpp_complex.hpp>

#include <complex>
#include <vector>

namespace zoomer
{

struct Image
{
    Image(int width, int height);
    Image(const Image &) = default;
    Image(Image &&) = default;
    ~Image() = default;
    Image &operator=(const Image &) = default;
    Image &operator=(Image &&) = default;

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

using DComplex = std::complex<double>;
using DComplexValue = typename DComplex::value_type;
using CppComplex = boost::multiprecision::cpp_complex_50;
using CppComplexValue = typename CppComplex::value_type;

template <typename Complex, typename Value = typename Complex::value_type>
static bool bailout(const Complex &z)
{
    using std::norm;
    return norm(z) > 4.0;
}

template <typename Complex>
static Complex formula(Complex z, const Complex &c)
{
    z *= z;
    z += c;
    return z;
}

template <typename Complex, typename Value = typename Complex::value_type>
Image plot(Complex center, Value magnification, int max_iter, int width, int height)
{
    Image result{width, height};
    const Value left{center.real() - magnification / 2.0};
    const Value bottom{center.imag() - magnification / 2.0};
    const Value dr{magnification / width};
    const Value di{magnification / height};

    Value im{bottom};
    for (int y = 0; y < height; ++y)
    {
        Value re{left};
        for (int x = 0; x < width; ++x)
        {
            const Complex c{re, im};
            Complex z{c};
            int i;
            for (i = 1; i < max_iter; ++i)
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
