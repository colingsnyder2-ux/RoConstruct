// from server: 58% by atomic.potato
struct S
{
    unsigned char pad[0x15];
    void f(unsigned char value);
};

void S::f(unsigned char value)
{
    if (pad[0x14] != 0 && pad[9] == 0 && value == pad[8])
    {
        pad[0x14] = 0;
    }
}
