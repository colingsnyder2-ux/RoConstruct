// from server: 73% by atomic.potato
struct S
{
    unsigned char pad[0xdc];
    unsigned char value;
    void f(unsigned char);
};

void S::f(unsigned char v)
{
    if (value != v)
    {
        value = v;
        *(int*)0x00b7b1c0 = 0;
    }
}
