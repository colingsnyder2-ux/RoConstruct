// from server: 100% by nuck16
// roc 2009-12 0045e010  unit: RBX::Stats::StatsService  size: 66 bytes
//
// 0045e010  51                   push ecx
// 0045e011  56                   push esi
// 0045e012  c744240400000000     mov dword ptr [esp + 4], 0
// 0045e01a  e8f1e5fbff           call 0x41c610
// 0045e01f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0045e023  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0045e027  83ec10               sub esp, 0x10
// 0045e02a  8bd4                 mov edx, esp
// 0045e02c  890a                 mov dword ptr [edx], ecx
// 0045e02e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0045e032  894a04               mov dword ptr [edx + 4], ecx
// 0045e035  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0045e039  894a08               mov dword ptr [edx + 8], ecx
// 0045e03c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0045e040  894a0c               mov dword ptr [edx + 0xc], ecx
// 0045e043  56                   push esi
// 0045e044  8bc8                 mov ecx, eax
// 0045e046  e845fbffff           call 0x45db90
// 0045e04b  8bc6                 mov eax, esi
// 0045e04d  5e                   pop esi
// 0045e04e  59                   pop ecx
// 0045e04f  c21400               ret 0x14

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
