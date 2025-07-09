#include <deep-zoom/args.h>
#include <deep-zoom/deep-zoom.h>

int main(int argc, const char *argv[])
{
    std::vector<std::string_view> arguments = zoomer::args(argc, argv);
    return 0;
}
