// from server: 100% by nuck16
// roc 2009-12 00521830  unit: RBX::Network::Players::Plugin  size: 66 bytes
//
// 00521830  51                   push ecx
// 00521831  56                   push esi
// 00521832  c744240400000000     mov dword ptr [esp + 4], 0
// 0052183a  e8e1bdfeff           call 0x50d620
// 0052183f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00521843  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00521847  83ec10               sub esp, 0x10
// 0052184a  8bd4                 mov edx, esp
// 0052184c  890a                 mov dword ptr [edx], ecx
// 0052184e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00521852  894a04               mov dword ptr [edx + 4], ecx
// 00521855  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00521859  894a08               mov dword ptr [edx + 8], ecx
// 0052185c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00521860  894a0c               mov dword ptr [edx + 0xc], ecx
// 00521863  56                   push esi
// 00521864  8bc8                 mov ecx, eax
// 00521866  e885abffff           call 0x51c3f0
// 0052186b  8bc6                 mov eax, esi
// 0052186d  5e                   pop esi
// 0052186e  59                   pop ecx
// 0052186f  c21400               ret 0x14

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
