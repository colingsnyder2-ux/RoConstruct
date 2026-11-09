// from server: 53% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl G1_func_00495f40(int *);
extern "C" int __cdecl G1_func_00983b6a(int);
extern "C" int __cdecl G1_func_00b229ec(int, int);

int S::f()
{
    int value = G1_func_00495f40((int *)((char *)this + 0x0c));
    if (value)
        return G1_func_00b229ec(0x00debe7c, G1_func_00983b6a(value));
    return 0;
}
