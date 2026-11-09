// from server: 80% by atomic.potato
struct S
{
    unsigned char value;
    void f(unsigned char);
};

void S::f(unsigned char v)
{
    if (v == *(unsigned char*)((char*)this + 0x180))
        return;

    *(unsigned char*)((char*)this + 0x180) = v;
    *(unsigned long*)0x00b927e8 = 0x00b927e8;
}
