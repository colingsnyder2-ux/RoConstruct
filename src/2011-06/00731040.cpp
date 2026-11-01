// from server: 100% by tester
struct S
{
    char padding[0xa0];
    short value;
    int f();
};

extern void G1_func_00730df0();

int S::f()
{
    G1_func_00730df0();
    return value;
}
