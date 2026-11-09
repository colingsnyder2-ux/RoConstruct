// from server: 100% by nuck16
// roc 2009-12 00521880  unit: RBX::Network::Players::Plugin  size: 66 bytes
//
// 00521880  51                   push ecx
// 00521881  56                   push esi
// 00521882  c744240400000000     mov dword ptr [esp + 4], 0
// 0052188a  e831befeff           call 0x50d6c0
// 0052188f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00521893  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00521897  83ec10               sub esp, 0x10
// 0052189a  8bd4                 mov edx, esp
// 0052189c  890a                 mov dword ptr [edx], ecx
// 0052189e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005218a2  894a04               mov dword ptr [edx + 4], ecx
// 005218a5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005218a9  894a08               mov dword ptr [edx + 8], ecx
// 005218ac  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005218b0  894a0c               mov dword ptr [edx + 0xc], ecx
// 005218b3  56                   push esi
// 005218b4  8bc8                 mov ecx, eax
// 005218b6  e895acffff           call 0x51c550
// 005218bb  8bc6                 mov eax, esi
// 005218bd  5e                   pop esi
// 005218be  59                   pop ecx
// 005218bf  c21400               ret 0x14

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
