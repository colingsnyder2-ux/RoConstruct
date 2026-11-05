// from server: 91% by atomic.potato
typedef long LONG;
typedef unsigned long DWORD;

struct CRITICAL_SECTION;

extern "C" void __stdcall EnterCriticalSection(CRITICAL_SECTION *);
extern "C" LONG __stdcall InterlockedDecrement(volatile LONG *);
extern "C" void __stdcall LeaveCriticalSection(CRITICAL_SECTION *);

extern "C" void * __cdecl sub_7b17b0();
extern "C" void __cdecl sub_98b204(void *);
extern "C" void __cdecl sub_98b200(void *);
extern "C" void __cdecl sub_98b208(const char *);

struct Body
{
    void __cdecl f(void *);
};

void Body::f(void *p)
{
    void *esi = sub_7b17b0();
    sub_98b204(esi);
    *(void **)p = *(void **)((char *)esi + 0x18);
    *(void **)((char *)esi + 0x18) = p;
    sub_98b200(esi);
    sub_98b208((const char *)0x00b7b424);
}
