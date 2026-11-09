// from server: 72% by atomic.potato
extern "C" void G1_func_0040C080(void *);

struct S
{
    void f(void *);
    char padding[0xb4];
    void *field_B4;
};

void S::f(void *value)
{
    if (field_B4 != value)
    {
        field_B4 = value;
        G1_func_0040C080((void *)0x00B7B060);
    }
}
