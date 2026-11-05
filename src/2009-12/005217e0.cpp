// from server: 100% by nuck16
// roc 2009-12 005217e0  unit: RBX::Network::Players::Plugin  size: 66 bytes
//
// 005217e0  51                   push ecx
// 005217e1  56                   push esi
// 005217e2  c744240400000000     mov dword ptr [esp + 4], 0
// 005217ea  e871bffeff           call 0x50d760
// 005217ef  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005217f3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005217f7  83ec10               sub esp, 0x10
// 005217fa  8bd4                 mov edx, esp
// 005217fc  890a                 mov dword ptr [edx], ecx
// 005217fe  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00521802  894a04               mov dword ptr [edx + 4], ecx
// 00521805  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00521809  894a08               mov dword ptr [edx + 8], ecx
// 0052180c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00521810  894a0c               mov dword ptr [edx + 0xc], ecx
// 00521813  56                   push esi
// 00521814  8bc8                 mov ecx, eax
// 00521816  e875aaffff           call 0x51c290
// 0052181b  8bc6                 mov eax, esi
// 0052181d  5e                   pop esi
// 0052181e  59                   pop ecx
// 0052181f  c21400               ret 0x14

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
