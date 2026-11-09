// from server: 100% by nuck16
// roc 2009-12 00770f90  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00770f90
//
// 00770f90  51                   push ecx
// 00770f91  56                   push esi
// 00770f92  c744240400000000     mov dword ptr [esp + 4], 0
// 00770f9a  e861feffff           call 0x770e00
// 00770f9f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00770fa3  8b542410             mov edx, dword ptr [esp + 0x10]
// 00770fa7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00770fab  51                   push ecx
// 00770fac  52                   push edx
// 00770fad  56                   push esi
// 00770fae  8bc8                 mov ecx, eax
// 00770fb0  e8fbe3ffff           call 0x76f3b0
// 00770fb5  8bc6                 mov eax, esi
// 00770fb7  5e                   pop esi
// 00770fb8  59                   pop ecx
// 00770fb9  c20c00               ret 0xc

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
