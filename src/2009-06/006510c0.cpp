// from server: 100% by EspClaude
// roc 2009-06 006510c0  unit: RBX::Profiling::Profiler  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006510c0
//
// 006510c0  56                   push esi
// 006510c1  8bf1                 mov esi, ecx
// 006510c3  8d8e20c00000         lea ecx, [esi + 0xc020]
// 006510c9  c7064cf98d00         mov dword ptr [esi], 0x8df94c
// 006510cf  ff15c4e48900         call dword ptr [0x89e4c4]
// 006510d5  f644240801           test byte ptr [esp + 8], 1
// 006510da  7409                 je 0x6510e5
// 006510dc  56                   push esi
// 006510dd  e850790c00           call 0x718a32
// 006510e2  83c404               add esp, 4
// 006510e5  8bc6                 mov eax, esi
// 006510e7  5e                   pop esi
// 006510e8  c20400               ret 4
// copied from an identical function in another client (function ?destroy@Profiler@@QAEPAU1@I@Z)

typedef void (__thiscall *StringDestructor)(void *);

extern StringDestructor destroyString;
extern void *profilerVtable[];
void __cdecl operator delete(void *);

struct Profiler
{
    void **vtable;
    char padding[0xC01C];
    char stringStorage[28];

    Profiler *__thiscall destroy(unsigned int flags);
};

Profiler *__thiscall Profiler::destroy(unsigned int flags)
{
    vtable = profilerVtable;
    destroyString(stringStorage);
    if (flags & 1)
        operator delete(this);
    return this;
}