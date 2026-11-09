// from server: 100% by nuck16
// roc 2009-12 005218d0  unit: RBX::Network::Players::Plugin  size: 66 bytes
//
// 005218d0  51                   push ecx
// 005218d1  56                   push esi
// 005218d2  c744240400000000     mov dword ptr [esp + 4], 0
// 005218da  e8c103faff           call 0x4c1ca0
// 005218df  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005218e3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005218e7  83ec10               sub esp, 0x10
// 005218ea  8bd4                 mov edx, esp
// 005218ec  890a                 mov dword ptr [edx], ecx
// 005218ee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005218f2  894a04               mov dword ptr [edx + 4], ecx
// 005218f5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005218f9  894a08               mov dword ptr [edx + 8], ecx
// 005218fc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00521900  894a0c               mov dword ptr [edx + 0xc], ecx
// 00521903  56                   push esi
// 00521904  8bc8                 mov ecx, eax
// 00521906  e8a5adffff           call 0x51c6b0
// 0052190b  8bc6                 mov eax, esi
// 0052190d  5e                   pop esi
// 0052190e  59                   pop ecx
// 0052190f  c21400               ret 0x14

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
