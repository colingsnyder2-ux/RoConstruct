// from server: 100% by nuck16
// roc 2009-12 00687040  unit: RBX::ChangeHistoryService  size: 66 bytes
//
// 00687040  51                   push ecx
// 00687041  56                   push esi
// 00687042  c744240400000000     mov dword ptr [esp + 4], 0
// 0068704a  e8c155d9ff           call 0x41c610
// 0068704f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00687053  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00687057  83ec10               sub esp, 0x10
// 0068705a  8bd4                 mov edx, esp
// 0068705c  890a                 mov dword ptr [edx], ecx
// 0068705e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00687062  894a04               mov dword ptr [edx + 4], ecx
// 00687065  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00687069  894a08               mov dword ptr [edx + 8], ecx
// 0068706c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00687070  894a0c               mov dword ptr [edx + 0xc], ecx
// 00687073  56                   push esi
// 00687074  8bc8                 mov ecx, eax
// 00687076  e895e1ffff           call 0x685210
// 0068707b  8bc6                 mov eax, esi
// 0068707d  5e                   pop esi
// 0068707e  59                   pop ecx
// 0068707f  c21400               ret 0x14

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
