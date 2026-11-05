// from server: 100% by atomic.potato
struct EventDesc
{
    int value;
    int* marker;
    EventDesc& f(EventDesc&);
};

EventDesc& EventDesc::f(EventDesc& other)
{
    value = other.value;
    marker = other.marker;
    if (marker)
        ++*marker;
    return *this;
}
