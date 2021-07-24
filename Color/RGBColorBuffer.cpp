
#include "RGBColorBuffer.hpp"
#include "Shared/Shared.hpp"
#include "RGBColor.hpp"

GFA::RGBColorBuffer::RGBColorBuffer()
    :   width_(0),
        height_(0),
        size_(0),
        dataPtr_(0)
{
}

GFA::RGBColorBuffer::RGBColorBuffer(const GFA::Size &width, const GFA::Size &height)
    :   width_(width),
        height_(height),
        size_((width_*4)*height_),
        dataPtr_(new GFA::Scalar[size_])
{
}

GFA::RGBColorBuffer::~RGBColorBuffer()
{
   if (dataPtr_ != 0) delete[] dataPtr_;
}

const GFA::Size & GFA::RGBColorBuffer::width() const
{
    return width_;
}

const GFA::Size & GFA::RGBColorBuffer::height() const
{
    return height_;
}

void GFA::RGBColorBuffer::setPixel(
    const GFA::Index &x, const GFA::Index &y, const GFA::RGBColor &col)
{
    if (x >= width_ || y >= height_) return;
    dataPtr_[x*4 + y*width_*4] = col.r;
    dataPtr_[x*4 + 1 + y*width_*4] = col.g;
    dataPtr_[x*4 + 2 + y*width_*4] = col.b;
    dataPtr_[x*4 + 3 + y*width_*4] = col.a;
}

GFA::RGBColor GFA::RGBColorBuffer::getPixel(const Index &x, const Index &y)
{
    GFA::RGBColor col;
    col.r = dataPtr_[x*4 + y*width_*4];
    col.g = dataPtr_[x*4 + 1 + y*width_*4];
    col.b = dataPtr_[x*4 + 2 + y*width_*4];
    col.a = dataPtr_[x*4 + 3 + y*width_*4];
    return col;
}

