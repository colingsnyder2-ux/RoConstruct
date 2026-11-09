// from server: 100% by nuck16
// roc 2009-12 00770ed0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00770ed0
//
// 00770ed0  51                   push ecx
// 00770ed1  56                   push esi
// 00770ed2  c744240400000000     mov dword ptr [esp + 4], 0
// 00770eda  e881ffceff           call 0x460e60
// 00770edf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00770ee3  8b542410             mov edx, dword ptr [esp + 0x10]
// 00770ee7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00770eeb  51                   push ecx
// 00770eec  52                   push edx
// 00770eed  56                   push esi
// 00770eee  8bc8                 mov ecx, eax
// 00770ef0  e8bbdfffff           call 0x76eeb0
// 00770ef5  8bc6                 mov eax, esi
// 00770ef7  5e                   pop esi
// 00770ef8  59                   pop ecx
// 00770ef9  c20c00               ret 0xc

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
