// from server: 62% by atomic.potato
struct S
{
    void* pad;
    void* object;

    void f();
};

extern "C" void* __cdecl G1_func_00495f40(void*);
extern "C" void* __cdecl G1_func_00983b6a(void*);
extern "C" int G1_type_info_compare(void*, void*);

S* const G1_global_00debc08 = (S*)0x00debc08;

void S::f()
{
    void* value = G1_func_00495f40(((void**)object)[0xac4 / 4]);
    if (value)
    {
        value = G1_func_00983b6a(value);
        G1_type_info_compare(G1_global_00debc08, value);
    }
}
