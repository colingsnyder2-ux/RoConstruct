// from server: 100% by tester
struct PolyPair
{
    int first;
    int second;
    int value(int selector);
};

int PolyPair::value(int selector)
{
    if (selector == 0)
        return *(int *)((char *)this + 0x18);
    return *(int *)((char *)this + 0x1c);
}
