// from server: 56% by atomic.potato
struct CornerWedgePoly
{
    int f();
};

int CornerWedgePoly::f()
{
    return *(unsigned char *)((char *)this + 0x18) & 0xc0;
}
