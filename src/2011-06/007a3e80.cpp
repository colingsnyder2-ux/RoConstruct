// from server: 100% by atomic.potato
struct PrismPoly_007a3e80
{
    int pad;
    int base;
    int get(int index);
};

int PrismPoly_007a3e80::get(int index)
{
    return base + index * 32;
}
