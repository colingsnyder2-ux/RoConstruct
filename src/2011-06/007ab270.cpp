// from server: 51% by atomic.potato
struct CornerWedgePoly
{
    int f();
    int padding[6];
};

int CornerWedgePoly::f()
{
    return padding[6] & 0x300;
}
