// from server: 97% by atomic.potato
struct S
{
};

extern "C" void *__cdecl sub_401920();
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" long __stdcall InterlockedDecrement(long *);
extern "C" void __stdcall LeaveCriticalSection(void *);
extern "C" void __stdcall sub_98B208(void *);

void *g_98B200;
void *g_98B204;
void *g_98B208;
void *g_B7A128;

int __cdecl f(void **p)
{
    void *esi = sub_401920();
    ((void (__stdcall *)(void *))g_98B204)(esi);
    *p = *(void **)((char *)esi + 0x18);
    *(void **)((char *)esi + 0x18) = p;
    ((void (__stdcall *)(void *))g_98B200)(esi);
    ((void (__stdcall *)(void *))g_98B208)((void *)0x00B7A128);
    return 0;
}
