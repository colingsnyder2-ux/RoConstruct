// from server: 100% by atomic.potato
struct S
{
    char padding[0x9a];
    short value;
    int f();
};

extern void G1_func_00730df0();

int S::f()
{
    G1_func_00730df0();
    return value;
}
