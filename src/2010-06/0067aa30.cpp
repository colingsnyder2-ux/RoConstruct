// from server: 100% by atomic.potato
struct S
{
    void f(unsigned char a, unsigned char b);
};

void S::f(unsigned char a, unsigned char b)
{
    *((unsigned char*)this + 0x14c) = a;
    *((unsigned char*)this + 0x14d) = b;
}
