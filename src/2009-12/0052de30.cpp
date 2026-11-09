// from server: 100% by nuck16
// roc 2009-12 0052de30  unit: RBX::Network::Server  size: 66 bytes
//
// 0052de30  51                   push ecx
// 0052de31  56                   push esi
// 0052de32  c744240400000000     mov dword ptr [esp + 4], 0
// 0052de3a  e8d1e7eeff           call 0x41c610
// 0052de3f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0052de43  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0052de47  83ec10               sub esp, 0x10
// 0052de4a  8bd4                 mov edx, esp
// 0052de4c  890a                 mov dword ptr [edx], ecx
// 0052de4e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0052de52  894a04               mov dword ptr [edx + 4], ecx
// 0052de55  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0052de59  894a08               mov dword ptr [edx + 8], ecx
// 0052de5c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0052de60  894a0c               mov dword ptr [edx + 0xc], ecx
// 0052de63  56                   push esi
// 0052de64  8bc8                 mov ecx, eax
// 0052de66  e8c5f0ffff           call 0x52cf30
// 0052de6b  8bc6                 mov eax, esi
// 0052de6d  5e                   pop esi
// 0052de6e  59                   pop ecx
// 0052de6f  c21400               ret 0x14

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
