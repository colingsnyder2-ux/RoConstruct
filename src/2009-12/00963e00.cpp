// from server: 57% by atomic.potato
extern "C" void __cdecl G1_func_007f539a(int);

struct S
{
};

void __cdecl f(int value)
{
    G1_func_007f539a(*(int *)((char *)value - 0x38) ^ value);
}
