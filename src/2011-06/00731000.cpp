// from server: 100% by tester
struct S
{
    int f();
    char padding[0x98];
    short value;
};

extern "C" void G1_func_00730df0();

int S::f()
{
    G1_func_00730df0();
    return (int)value;
}
