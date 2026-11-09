// from server: 100% by nuck16
// roc 2009-12 00528380  unit: RBX::Network::Client  size: 66 bytes
//
// 00528380  51                   push ecx
// 00528381  56                   push esi
// 00528382  c744240400000000     mov dword ptr [esp + 4], 0
// 0052838a  e81199f9ff           call 0x4c1ca0
// 0052838f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00528393  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00528397  83ec10               sub esp, 0x10
// 0052839a  8bd4                 mov edx, esp
// 0052839c  890a                 mov dword ptr [edx], ecx
// 0052839e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005283a2  894a04               mov dword ptr [edx + 4], ecx
// 005283a5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005283a9  894a08               mov dword ptr [edx + 8], ecx
// 005283ac  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005283b0  894a0c               mov dword ptr [edx + 0xc], ecx
// 005283b3  56                   push esi
// 005283b4  8bc8                 mov ecx, eax
// 005283b6  e815dfffff           call 0x5262d0
// 005283bb  8bc6                 mov eax, esi
// 005283bd  5e                   pop esi
// 005283be  59                   pop ecx
// 005283bf  c21400               ret 0x14

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
