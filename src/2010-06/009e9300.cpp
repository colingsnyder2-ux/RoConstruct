// from server: 100% by colin
namespace ns_ROCX000002 {
extern void (__cdecl *deallocBytes)(void*);

extern void* g_00b7cd28;

void fn_ROCX000002_0097ee50()
{
    if (g_00b7cd28)
        deallocBytes(g_00b7cd28);
}
}
