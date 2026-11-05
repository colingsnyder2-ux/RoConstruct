// from server: 100% by atomic.potato
struct S
{
    int f();
    char padding[0xa2];
    short value;
};

extern "C" void G1_func_00730df0();

int S::f()
{
    G1_func_00730df0();
    return (int)value;
}
