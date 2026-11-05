// from server: 90% by atomic.potato
extern "C" void __cdecl G1_func_007ef7b0();
extern "C" void __stdcall DeleteCriticalSection(void *);
extern char G_global_00b99dbc;

void func_0098a4c0()
{
    G1_func_007ef7b0();
    DeleteCriticalSection(&G_global_00b99dbc);
}
