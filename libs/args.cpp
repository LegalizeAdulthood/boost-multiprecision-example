#include "deep-zoom/args.h"

namespace zoomer
{

std::vector<std::string_view> args(int argc, const char *argv[])
{
    std::vector<std::string_view> args;
    args.reserve(argc);
    for (int i = 0; i < argc; ++i)
    {
        args.emplace_back(argv[i]);
    }
    return args;
}

} // namespace zoomer
