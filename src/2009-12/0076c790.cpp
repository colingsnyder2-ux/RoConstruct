// from server: 100% by nuck16
// roc 2009-12 0076c790  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 66 bytes
//
// 0076c790  51                   push ecx
// 0076c791  56                   push esi
// 0076c792  c744240400000000     mov dword ptr [esp + 4], 0
// 0076c79a  e8c146cfff           call 0x460e60
// 0076c79f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0076c7a3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0076c7a7  83ec10               sub esp, 0x10
// 0076c7aa  8bd4                 mov edx, esp
// 0076c7ac  890a                 mov dword ptr [edx], ecx
// 0076c7ae  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0076c7b2  894a04               mov dword ptr [edx + 4], ecx
// 0076c7b5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0076c7b9  894a08               mov dword ptr [edx + 8], ecx
// 0076c7bc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0076c7c0  894a0c               mov dword ptr [edx + 0xc], ecx
// 0076c7c3  56                   push esi
// 0076c7c4  8bc8                 mov ecx, eax
// 0076c7c6  e825fcffff           call 0x76c3f0
// 0076c7cb  8bc6                 mov eax, esi
// 0076c7cd  5e                   pop esi
// 0076c7ce  59                   pop ecx
// 0076c7cf  c21400               ret 0x14

struct Ret
{
    Ret(const Ret &);
    ~Ret();
    void *p;
};

struct Arg
{
    int f0, f1, f2, f3;
};

struct Impl
{
    Ret g(Arg arg);
};

struct Getter { static Impl *get(); };

struct S
{
    Ret f(Arg arg);
};

Ret S::f(Arg arg)
{
    Impl *impl = Getter::get();
    return impl->g(arg);
}
