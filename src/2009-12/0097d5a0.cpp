// from server: 42% by atomic.potato
struct S
{
};

typedef void (__thiscall *CallA)(void *);
typedef void (__cdecl *CallB)(const char *);

S g_object;

void f_0097d5a0()
{
    CallA a = (CallA)0x0047e7b0;
    CallB b = (CallB)0x007f4929;
    a((void *)0x00ba1f54);
    b((const char *)0x0098a8c0);
}
