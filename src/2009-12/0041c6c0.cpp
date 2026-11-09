// from server: 100% by nuck16
// roc 2009-12 0041c6c0  unit: CSettingsExplorer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041c6c0
//
// 0041c6c0  51                   push ecx
// 0041c6c1  56                   push esi
// 0041c6c2  c744240400000000     mov dword ptr [esp + 4], 0
// 0041c6ca  e841ffffff           call 0x41c610
// 0041c6cf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0041c6d3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041c6d7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0041c6db  51                   push ecx
// 0041c6dc  52                   push edx
// 0041c6dd  56                   push esi
// 0041c6de  8bc8                 mov ecx, eax
// 0041c6e0  e83bfcffff           call 0x41c320
// 0041c6e5  8bc6                 mov eax, esi
// 0041c6e7  5e                   pop esi
// 0041c6e8  59                   pop ecx
// 0041c6e9  c20c00               ret 0xc

struct Ret
{
    Ret(const Ret &);
    ~Ret();
    void *p;
};

struct Impl
{
    Ret g(void *a0, void *a1);
};

struct Getter { static Impl *get(); };

struct S
{
    Ret f(void *a0, void *a1);
};

Ret S::f(void *a0, void *a1)
{
    Impl *impl = Getter::get();
    return impl->g(a0, a1);
}
