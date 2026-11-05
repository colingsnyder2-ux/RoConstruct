// from server: 81% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl G1_func_006a5fc0();
extern "C" void G2_func_00411f60(S *, const void *);

void S::f()
{
    G1_func_006a5fc0();
    G2_func_00411f60(this, (const void *)0x00ccf4b0);
    G2_func_00411f60(this, (const void *)0x00ccf464);
}
