// from server: 62% by atomic.potato
struct S
{
    void f(unsigned char value);
};

void S::f(unsigned char value)
{
    int x = -(int)value;
    x = (x >> 31) & 4;
    x |= *(int*)((char*)this + 0x58) & ~4;
    *(int*)((char*)this + 0x58) = x;
}
