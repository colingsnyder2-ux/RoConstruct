// from server: 79% by atomic.potato
struct PingItem
{
    PingItem *operator()(int);
};

extern "C" void __stdcall sub_5775a0(PingItem *);

PingItem *PingItem::operator()(int value)
{
    if (value & 1)
        sub_5775a0(this - 1);
    return this;
}
