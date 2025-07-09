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

} // namespace zoomer
