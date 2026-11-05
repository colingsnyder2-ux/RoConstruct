// from server: 48% by atomic.potato
struct SpatialFilter
{
    void f(void*& value);
};

void SpatialFilter::f(void*& value)
{
    if (value)
        value = static_cast<char*>(value) + 8;
}
