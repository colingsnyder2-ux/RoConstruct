// from server: 100% by atomic.potato
struct ViewRbxGfx
{
    void f(unsigned char value);
};

void ViewRbxGfx::f(unsigned char value)
{
    unsigned char zero = 0;
    ((unsigned char*)this)[0x20] = zero;
    if (value != 0)
        ((unsigned char*)this)[0x24] = zero;
}
