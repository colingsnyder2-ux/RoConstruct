// from server: 25% by atomic.potato
struct S
{
    void f(const void* value);
    char padding[0x90];
    unsigned long data[8];
};

void S::f(const void* value)
{
    const unsigned long* source = (const unsigned long*)value;
    int i;

    for (i = 0; i < 8; ++i)
        data[i] = source[i];

    data[0] = 0;
}
