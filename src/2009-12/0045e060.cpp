// from server: 100% by nuck16
// roc 2009-12 0045e060  unit: RBX::Stats::StatsService  size: 59 bytes
//
// 0045e060  51                   push ecx
// 0045e061  56                   push esi
// 0045e062  c744240400000000     mov dword ptr [esp + 4], 0
// 0045e06a  e8a1e5fbff           call 0x41c610
// 0045e06f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0045e073  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0045e077  83ec0c               sub esp, 0xc
// 0045e07a  8bd4                 mov edx, esp
// 0045e07c  890a                 mov dword ptr [edx], ecx
// 0045e07e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0045e082  894a04               mov dword ptr [edx + 4], ecx
// 0045e085  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0045e089  894a08               mov dword ptr [edx + 8], ecx
// 0045e08c  56                   push esi
// 0045e08d  8bc8                 mov ecx, eax
// 0045e08f  e85cfcffff           call 0x45dcf0
// 0045e094  8bc6                 mov eax, esi
// 0045e096  5e                   pop esi
// 0045e097  59                   pop ecx
// 0045e098  c21000               ret 0x10

struct Ret
{
    Ret(const Ret &);
    ~Ret();
    void *p;
};

struct Arg
{
    int f0, f1, f2;
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
