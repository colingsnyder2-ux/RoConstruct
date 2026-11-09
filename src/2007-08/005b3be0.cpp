// from server: 100% by colin
struct AssemblyHelper
{
    void method(int* a, int* b);
};

struct Assembly
{
    char pad[0x18];
    AssemblyHelper helper;
    void func(int arg);
};

void Assembly::func(int arg)
{
    int local[3];
    helper.method(&local[0], &arg);
}
