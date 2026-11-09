// from server: 71% by atomic.potato
struct S
{
    unsigned char pad0[8];
    unsigned char value;
    unsigned char pad9[11];
    unsigned char enabled;
    void f(unsigned char, unsigned char, unsigned char);
};

void S::f(unsigned char value, unsigned char, unsigned char)
{
    if (enabled && value == ((unsigned char *)this)[8])
    {
        ((void (__thiscall *)(S *))0x48d660)(this);
        enabled = 0;
    }
}
