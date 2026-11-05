// from server: 100% by atomic.potato
struct EventDesc
{
    int value;
    short field4;
    short field6;
    EventDesc& assign(const EventDesc& other);
};

EventDesc& EventDesc::assign(const EventDesc& other)
{
    value = other.value;
    field4 = other.field4;
    field6 = other.field6;
    return *this;
}
