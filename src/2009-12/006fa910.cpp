// from server: 100% by nuck16
// roc 2009-12 006fa910  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 66 bytes
//
// 006fa910  51                   push ecx
// 006fa911  56                   push esi
// 006fa912  c744240400000000     mov dword ptr [esp + 4], 0
// 006fa91a  e8e12ee1ff           call 0x50d800
// 006fa91f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006fa923  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006fa927  83ec10               sub esp, 0x10
// 006fa92a  8bd4                 mov edx, esp
// 006fa92c  890a                 mov dword ptr [edx], ecx
// 006fa92e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006fa932  894a04               mov dword ptr [edx + 4], ecx
// 006fa935  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006fa939  894a08               mov dword ptr [edx + 8], ecx
// 006fa93c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006fa940  894a0c               mov dword ptr [edx + 0xc], ecx
// 006fa943  56                   push esi
// 006fa944  8bc8                 mov ecx, eax
// 006fa946  e8a5e0ffff           call 0x6f89f0
// 006fa94b  8bc6                 mov eax, esi
// 006fa94d  5e                   pop esi
// 006fa94e  59                   pop ecx
// 006fa94f  c21400               ret 0x14

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
