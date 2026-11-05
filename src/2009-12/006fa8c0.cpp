// from server: 100% by nuck16
// roc 2009-12 006fa8c0  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 66 bytes
//
// 006fa8c0  51                   push ecx
// 006fa8c1  56                   push esi
// 006fa8c2  c744240400000000     mov dword ptr [esp + 4], 0
// 006fa8ca  e8d173dcff           call 0x4c1ca0
// 006fa8cf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006fa8d3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006fa8d7  83ec10               sub esp, 0x10
// 006fa8da  8bd4                 mov edx, esp
// 006fa8dc  890a                 mov dword ptr [edx], ecx
// 006fa8de  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006fa8e2  894a04               mov dword ptr [edx + 4], ecx
// 006fa8e5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006fa8e9  894a08               mov dword ptr [edx + 8], ecx
// 006fa8ec  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006fa8f0  894a0c               mov dword ptr [edx + 0xc], ecx
// 006fa8f3  56                   push esi
// 006fa8f4  8bc8                 mov ecx, eax
// 006fa8f6  e895dfffff           call 0x6f8890
// 006fa8fb  8bc6                 mov eax, esi
// 006fa8fd  5e                   pop esi
// 006fa8fe  59                   pop ecx
// 006fa8ff  c21400               ret 0x14

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
