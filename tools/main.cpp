#include <deep-zoom/args.h>
#include <deep-zoom/deep-zoom.h>

namespace
{

void report(const zoomer::Image &img)
{
}

}

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

    int width{800};
    int height{600};
    double magnification{1.0};
    for (int i = 0; i < count; ++i)
    {
        zoomer::Image img{zoomer::plot(center, magnification, width, height)};
        report(img);
    }

    return 0;
}
