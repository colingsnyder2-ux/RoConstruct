// from server: 100% by nuck16
// roc 2009-12 006a9540  unit: RBX::ScriptContext  size: 66 bytes
//
// 006a9540  51                   push ecx
// 006a9541  56                   push esi
// 006a9542  c744240400000000     mov dword ptr [esp + 4], 0
// 006a954a  e83123ffff           call 0x69b880
// 006a954f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006a9553  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006a9557  83ec10               sub esp, 0x10
// 006a955a  8bd4                 mov edx, esp
// 006a955c  890a                 mov dword ptr [edx], ecx
// 006a955e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006a9562  894a04               mov dword ptr [edx + 4], ecx
// 006a9565  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006a9569  894a08               mov dword ptr [edx + 8], ecx
// 006a956c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006a9570  894a0c               mov dword ptr [edx + 0xc], ecx
// 006a9573  56                   push esi
// 006a9574  8bc8                 mov ecx, eax
// 006a9576  e865d2ffff           call 0x6a67e0
// 006a957b  8bc6                 mov eax, esi
// 006a957d  5e                   pop esi
// 006a957e  59                   pop ecx
// 006a957f  c21400               ret 0x14

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
