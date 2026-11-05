// from server: 100% by atomic.potato
extern void (__cdecl *deallocBytes)(void*);

extern void* g_00b7cd28;

void func_0097ee50()
{
    if (g_00b7cd28)
        deallocBytes(g_00b7cd28);
}
