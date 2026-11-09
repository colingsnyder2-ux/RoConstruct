// from server: 100% by colin
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern void (__cdecl *deallocBytes)(void*);

extern void* g_00b7cd28;

void func_0097ee50()
{
    if (g_00b7cd28)
        deallocBytes(g_00b7cd28);
}