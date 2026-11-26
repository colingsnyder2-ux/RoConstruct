// from server: 100% by Xemicl
// roc 2012-06 00792d70  unit: RBX::Profiling::Profiler  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00792d70
//
// 00792d70  56                   push esi
// 00792d71  8bf1                 mov esi, ecx
// 00792d73  8d8e20c00000         lea ecx, [esi + 0xc020]
// 00792d79  c7061c2abb00         mov dword ptr [esi], 0xbb2a1c
// 00792d7f  ff153c26b200         call dword ptr [0xb2263c]
// 00792d85  f644240801           test byte ptr [esp + 8], 1
// 00792d8a  7409                 je 0x792d95
// 00792d8c  56                   push esi
// 00792d8d  e882f31e00           call 0x982114
// 00792d92  83c404               add esp, 4
// 00792d95  8bc6                 mov eax, esi
// 00792d97  5e                   pop esi
// 00792d98  c20400               ret 4
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