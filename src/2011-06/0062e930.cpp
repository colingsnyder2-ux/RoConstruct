// from server: 100% by atomic.potato
struct BackpackItem
{
    int f();
};

extern "C" int __cdecl G_0080b2ea(int, int, int, int, int);

int BackpackItem::f()
{
    int value = *(int *)((char *)this + 0x44);
    if (value != 0 &&
        G_0080b2ea(value, 0, 0xC071F8, 0xC1A750, 0) != 0)
        return 1;
    return 0;
}
