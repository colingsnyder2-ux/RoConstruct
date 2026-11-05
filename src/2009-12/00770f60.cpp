// from server: 100% by nuck16
// roc 2009-12 00770f60  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00770f60
//
// 00770f60  51                   push ecx
// 00770f61  56                   push esi
// 00770f62  c744240400000000     mov dword ptr [esp + 4], 0
// 00770f6a  e8310dd5ff           call 0x4c1ca0
// 00770f6f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00770f73  8b542410             mov edx, dword ptr [esp + 0x10]
// 00770f77  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00770f7b  51                   push ecx
// 00770f7c  52                   push edx
// 00770f7d  56                   push esi
// 00770f7e  8bc8                 mov ecx, eax
// 00770f80  e8ebe2ffff           call 0x76f270
// 00770f85  8bc6                 mov eax, esi
// 00770f87  5e                   pop esi
// 00770f88  59                   pop ecx
// 00770f89  c20c00               ret 0xc

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
