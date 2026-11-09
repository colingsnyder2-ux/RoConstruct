// from server: 100% by nuck16
// roc 2009-12 00770f30  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00770f30
//
// 00770f30  51                   push ecx
// 00770f31  56                   push esi
// 00770f32  c744240400000000     mov dword ptr [esp + 4], 0
// 00770f3a  e821ffceff           call 0x460e60
// 00770f3f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00770f43  8b542410             mov edx, dword ptr [esp + 0x10]
// 00770f47  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00770f4b  51                   push ecx
// 00770f4c  52                   push edx
// 00770f4d  56                   push esi
// 00770f4e  8bc8                 mov ecx, eax
// 00770f50  e8dbe1ffff           call 0x76f130
// 00770f55  8bc6                 mov eax, esi
// 00770f57  5e                   pop esi
// 00770f58  59                   pop ecx
// 00770f59  c20c00               ret 0xc

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
