// from server: 100% by nuck16
// roc 2009-12 00770ea0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00770ea0
//
// 00770ea0  51                   push ecx
// 00770ea1  56                   push esi
// 00770ea2  c744240400000000     mov dword ptr [esp + 4], 0
// 00770eaa  e8b1ffceff           call 0x460e60
// 00770eaf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00770eb3  8b542410             mov edx, dword ptr [esp + 0x10]
// 00770eb7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00770ebb  51                   push ecx
// 00770ebc  52                   push edx
// 00770ebd  56                   push esi
// 00770ebe  8bc8                 mov ecx, eax
// 00770ec0  e8abdeffff           call 0x76ed70
// 00770ec5  8bc6                 mov eax, esi
// 00770ec7  5e                   pop esi
// 00770ec8  59                   pop ecx
// 00770ec9  c20c00               ret 0xc

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
