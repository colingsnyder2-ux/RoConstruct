// from server: 36% by atomic.potato
struct S
{
    float value;
    void update(float);
};

void S::update(float v)
{
    if (value != v || value != value)
    {
        value = v;
        extern void __stdcall f(unsigned long);
        f(0x00e55a9c);
    }
}
