// from server: 100% by nuck16
// roc 2009-12 00440db0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00440db0
//
// 00440db0  51                   push ecx
// 00440db1  56                   push esi
// 00440db2  c744240400000000     mov dword ptr [esp + 4], 0
// 00440dba  e831f5fdff           call 0x4202f0
// 00440dbf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00440dc3  8b542410             mov edx, dword ptr [esp + 0x10]
// 00440dc7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00440dcb  51                   push ecx
// 00440dcc  52                   push edx
// 00440dcd  56                   push esi
// 00440dce  8bc8                 mov ecx, eax
// 00440dd0  e8fbe4ffff           call 0x43f2d0
// 00440dd5  8bc6                 mov eax, esi
// 00440dd7  5e                   pop esi
// 00440dd8  59                   pop ecx
// 00440dd9  c20c00               ret 0xc

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
