// from server: 100% by colin
struct AssemblyHelper
{
    void method(int* a, int* b);
};

struct Assembly
{
    char pad[0x24];
    AssemblyHelper helper;
    void func(int arg);
};

void Assembly::func(int arg)
{
    int local[3];
    helper.method(local, &arg);
}
