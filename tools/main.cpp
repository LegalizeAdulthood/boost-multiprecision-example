#include <deep-zoom/args.h>
#include <deep-zoom/deep-zoom.h>

#include <iostream>
#include <string_view>

namespace
{

constexpr std::string_view PLOT_CHARS{"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

void report(const zoomer::Image &img)
{
    for (int y = img.height() - 1; y >= 0; --y)
    {
        for (int x = 0; x < img.width(); ++x)
        {
            const size_t idx = img.get(x, y) % PLOT_CHARS.size();
            std::cout << PLOT_CHARS[idx] << PLOT_CHARS[idx];
        }
        std::cout << '\n';
    }
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
    int count{10};
    if (args.size() == 4)
    {
        count = std::stoi(std::string{args[3]});
    }

    int width{32};
    int height{32};
    double magnification{1.0};
    for (int i = 0; i < count; ++i)
    {
        zoomer::Image img{zoomer::plot(center, magnification, width, height)};
        std::cout << magnification << '\n';
        report(img);
        magnification /= 2.0;
    }

    return 0;
}
