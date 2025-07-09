#include <deep-zoom/args.h>
#include <deep-zoom/deep-zoom.h>

#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <string_view>

namespace
{

constexpr std::string_view PLOT_CHARS{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

bool report(const zoomer::Image &img)
{
    std::vector<int> histogram;
    histogram.resize(PLOT_CHARS.size());
    for (int y = img.height() - 1; y >= 0; --y)
    {
        for (int x = 0; x < img.width(); ++x)
        {
            const size_t idx = img.get(x, y) % PLOT_CHARS.size();
            ++histogram[idx];
            std::cout << PLOT_CHARS[idx] << PLOT_CHARS[idx];
        }
        std::cout << '\n';
    }
    std::cout << std::flush;
    int num_different{std::accumulate(
        histogram.begin(), histogram.end(), 0, [](int sum, int count) { return sum + (count > 0 ? 1 : 0); })};
    return num_different < 4;
}

template <typename Complex, typename Value = typename Complex::value_type>
void zoom(Complex center, bool pause, int &max_iter, Value &magnification)
{
    int width{32};
    int height{32};
    Value last_mag{.0};
    std::string dummy;
    using std::abs;
    while (abs(magnification - last_mag) > std::numeric_limits<Value>::epsilon() * Value(10))
    {
        zoomer::Image img{zoomer::plot(center, magnification, max_iter, width, height)};
        std::cout << max_iter << ' ' << magnification << '\n';
        if (report(img))
        {
            max_iter *= 2;
        }
        last_mag = magnification;
        magnification /= Value(2.0);
        if (pause)
        {
            std::getline(std::cin, dummy);
        }
    }
}

void big_zoom(const zoomer::DComplex &low_center, bool pause, int &max_iter, zoomer::DComplexValue low_mag)
{
    zoomer::CppComplex center{low_center};
    zoomer::CppComplexValue mag{low_mag};
    zoom(center, pause, max_iter, mag);
}

} // namespace

int main(int argc, const char *argv[])
{
    std::vector<std::string_view> args{zoomer::args(argc, argv)};
    std::complex<double> center{-1.5, 0.0};
    if (args.size() >= 3)
    {
        center = std::complex<double>(std::stod(std::string(args[1])), std::stod(std::string(args[2])));
    }

    bool pause{false};
    int max_iter{256};
    double magnification{1.0};
    zoom(center, pause, max_iter, magnification);
    big_zoom(center, pause, max_iter, magnification);

    return 0;
}
