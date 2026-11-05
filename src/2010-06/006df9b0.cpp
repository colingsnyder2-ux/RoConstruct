// from server: 73% by atomic.potato
struct S
{
    unsigned char value;
    void f(unsigned char);
};

void S::f(unsigned char value)
{
    if (value != *(unsigned char*)((char*)this + 0x2f0))
    {
        *(unsigned char*)((char*)this + 0x2f0) = value;
        *(unsigned long*)((char*)0x40c474) = 0xc20e5c;
    }
}
