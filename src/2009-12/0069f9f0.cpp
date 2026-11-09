// from server: 100% by atomic.potato
extern "C" void __cdecl UniversalTool(void *, void *, void *);
extern "C" void __cdecl UniversalTool2(void *, void *);

struct S
{
};

int __cdecl f(void *esi)
{
    void *p = *((void **)0x00b62b70);
    UniversalTool(esi, (void *)1, p);
    UniversalTool2(esi, (void *)0x009d2a6c);
    return 1;
}
