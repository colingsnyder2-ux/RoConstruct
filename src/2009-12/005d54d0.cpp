// from server: 100% by nuck16
// roc 2009-12 005d54d0  unit: RBX::MaterialBaseRefMaterialAdapter  size: 66 bytes
//
// 005d54d0  51                   push ecx
// 005d54d1  56                   push esi
// 005d54d2  c744240400000000     mov dword ptr [esp + 4], 0
// 005d54da  e8a19ce9ff           call 0x46f180
// 005d54df  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d54e3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d54e7  83ec10               sub esp, 0x10
// 005d54ea  8bd4                 mov edx, esp
// 005d54ec  890a                 mov dword ptr [edx], ecx
// 005d54ee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d54f2  894a04               mov dword ptr [edx + 4], ecx
// 005d54f5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d54f9  894a08               mov dword ptr [edx + 8], ecx
// 005d54fc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d5500  894a0c               mov dword ptr [edx + 0xc], ecx
// 005d5503  56                   push esi
// 005d5504  8bc8                 mov ecx, eax
// 005d5506  e865e9ffff           call 0x5d3e70
// 005d550b  8bc6                 mov eax, esi
// 005d550d  5e                   pop esi
// 005d550e  59                   pop ecx
// 005d550f  c21400               ret 0x14

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
