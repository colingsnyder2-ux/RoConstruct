// from server: 83% by atomic.potato
struct S
{
    unsigned char value[0x1cd];
    int f(unsigned char);
};

extern "C" void SetValue();

int S::f(unsigned char v)
{
    if (value[0x1cc] != v)
    {
        value[0x1cc] = v;
        SetValue();
    }
    return 0;
}
