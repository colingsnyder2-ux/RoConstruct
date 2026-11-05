// from server: 100% by nuck16
// roc 2009-12 0070f150  unit: RBX::VInsertService::?$BoundYieldFuncDesc  size: 66 bytes
//
// 0070f150  51                   push ecx
// 0070f151  56                   push esi
// 0070f152  c744240400000000     mov dword ptr [esp + 4], 0
// 0070f15a  e881e3dfff           call 0x50d4e0
// 0070f15f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0070f163  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0070f167  83ec10               sub esp, 0x10
// 0070f16a  8bd4                 mov edx, esp
// 0070f16c  890a                 mov dword ptr [edx], ecx
// 0070f16e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0070f172  894a04               mov dword ptr [edx + 4], ecx
// 0070f175  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0070f179  894a08               mov dword ptr [edx + 8], ecx
// 0070f17c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0070f180  894a0c               mov dword ptr [edx + 0xc], ecx
// 0070f183  56                   push esi
// 0070f184  8bc8                 mov ecx, eax
// 0070f186  e805b2ffff           call 0x70a390
// 0070f18b  8bc6                 mov eax, esi
// 0070f18d  5e                   pop esi
// 0070f18e  59                   pop ecx
// 0070f18f  c21400               ret 0x14

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
