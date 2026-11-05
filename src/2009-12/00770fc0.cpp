// from server: 100% by nuck16
// roc 2009-12 00770fc0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00770fc0
//
// 00770fc0  51                   push ecx
// 00770fc1  56                   push esi
// 00770fc2  c744240400000000     mov dword ptr [esp + 4], 0
// 00770fca  e8d10cd5ff           call 0x4c1ca0
// 00770fcf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00770fd3  8b542410             mov edx, dword ptr [esp + 0x10]
// 00770fd7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00770fdb  51                   push ecx
// 00770fdc  52                   push edx
// 00770fdd  56                   push esi
// 00770fde  8bc8                 mov ecx, eax
// 00770fe0  e80be5ffff           call 0x76f4f0
// 00770fe5  8bc6                 mov eax, esi
// 00770fe7  5e                   pop esi
// 00770fe8  59                   pop ecx
// 00770fe9  c20c00               ret 0xc

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
