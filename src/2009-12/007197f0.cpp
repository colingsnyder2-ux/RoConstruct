// from server: 100% by nuck16
// roc 2009-12 007197f0  unit: RBX::$$A6AXPAVPrimitive::?$signal::slot  size: 66 bytes
//
// 007197f0  51                   push ecx
// 007197f1  56                   push esi
// 007197f2  c744240400000000     mov dword ptr [esp + 4], 0
// 007197fa  e871feffff           call 0x719670
// 007197ff  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00719803  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00719807  83ec10               sub esp, 0x10
// 0071980a  8bd4                 mov edx, esp
// 0071980c  890a                 mov dword ptr [edx], ecx
// 0071980e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00719812  894a04               mov dword ptr [edx + 4], ecx
// 00719815  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00719819  894a08               mov dword ptr [edx + 8], ecx
// 0071981c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00719820  894a0c               mov dword ptr [edx + 0xc], ecx
// 00719823  56                   push esi
// 00719824  8bc8                 mov ecx, eax
// 00719826  e865faffff           call 0x719290
// 0071982b  8bc6                 mov eax, esi
// 0071982d  5e                   pop esi
// 0071982e  59                   pop ecx
// 0071982f  c21400               ret 0x14

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
