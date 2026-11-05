// from server: 54% by atomic.potato
extern "C" void __stdcall f(void *);

struct S
{
    char padding[0x39c];
    float value;
    void set(float);
};

void S::set(float v)
{
    if (value <= v)
    {
        value = v;
        f((void *)0xe55968);
    }
}
