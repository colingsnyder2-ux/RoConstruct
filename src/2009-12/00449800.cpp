// from server: 75% by atomic.potato
extern "C" void G1_func_0040C080(int);

struct S
{
    void f(int value);
    char padding[176];
    int field_b0;
};

void S::f(int value)
{
    if (value == field_b0)
        return;

    field_b0 = value;
    G1_func_0040C080(0x00b7b038);
}
