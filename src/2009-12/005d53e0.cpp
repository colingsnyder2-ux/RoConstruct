// from server: 100% by nuck16
// roc 2009-12 005d53e0  unit: RBX::MaterialBaseRefMaterialAdapter  size: 66 bytes
//
// 005d53e0  51                   push ecx
// 005d53e1  56                   push esi
// 005d53e2  c744240400000000     mov dword ptr [esp + 4], 0
// 005d53ea  e801afe4ff           call 0x4202f0
// 005d53ef  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d53f3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d53f7  83ec10               sub esp, 0x10
// 005d53fa  8bd4                 mov edx, esp
// 005d53fc  890a                 mov dword ptr [edx], ecx
// 005d53fe  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d5402  894a04               mov dword ptr [edx + 4], ecx
// 005d5405  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d5409  894a08               mov dword ptr [edx + 8], ecx
// 005d540c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d5410  894a0c               mov dword ptr [edx + 0xc], ecx
// 005d5413  56                   push esi
// 005d5414  8bc8                 mov ecx, eax
// 005d5416  e835e6ffff           call 0x5d3a50
// 005d541b  8bc6                 mov eax, esi
// 005d541d  5e                   pop esi
// 005d541e  59                   pop ecx
// 005d541f  c21400               ret 0x14

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
