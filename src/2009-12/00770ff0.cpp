// from server: 100% by nuck16
// roc 2009-12 00770ff0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00770ff0
//
// 00770ff0  51                   push ecx
// 00770ff1  56                   push esi
// 00770ff2  c744240400000000     mov dword ptr [esp + 4], 0
// 00770ffa  e801feffff           call 0x770e00
// 00770fff  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00771003  8b542410             mov edx, dword ptr [esp + 0x10]
// 00771007  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0077100b  51                   push ecx
// 0077100c  52                   push edx
// 0077100d  56                   push esi
// 0077100e  8bc8                 mov ecx, eax
// 00771010  e81be6ffff           call 0x76f630
// 00771015  8bc6                 mov eax, esi
// 00771017  5e                   pop esi
// 00771018  59                   pop ecx
// 00771019  c20c00               ret 0xc

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
