// from server: 64% by atomic.potato
typedef int (__thiscall *Fn495f40)(void *);
typedef void *(__cdecl *Fn983b6a)(int);
typedef void (__thiscall *FnGlobal)(void *, void *);

extern "C" FnGlobal g_b229ec;

struct TToolVerb
{
    char padding[12];
    void *field_0c;
    void f();
};

void TToolVerb::f()
{
    int value = ((Fn495f40)0x495f40)(*(void **)((char *)field_0c + 0xac4));
    if (value)
    {
        void *result = ((Fn983b6a)0x983b6a)(value);
        g_b229ec((void *)0xdec3f4, result);
    }
}
