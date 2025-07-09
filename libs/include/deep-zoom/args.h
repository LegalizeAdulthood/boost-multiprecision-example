#pragma once

#include <string_view>
#include <vector>

namespace zoomer
{

std::vector<std::string_view> args(int argc, const char *argv[]);

} // namespace zoomer
