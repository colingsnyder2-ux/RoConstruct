// from server: 100% by nuck16
// roc 2009-12 0070f100  unit: RBX::VInsertService::?$BoundYieldFuncDesc  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0070f100
//
// 0070f100  51                   push ecx
// 0070f101  56                   push esi
// 0070f102  c744240400000000     mov dword ptr [esp + 4], 0
// 0070f10a  e871f1ffff           call 0x70e280
// 0070f10f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0070f113  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0070f117  83ec10               sub esp, 0x10
// 0070f11a  8bd4                 mov edx, esp
// 0070f11c  890a                 mov dword ptr [edx], ecx
// 0070f11e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0070f122  894a04               mov dword ptr [edx + 4], ecx
// 0070f125  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0070f129  894a08               mov dword ptr [edx + 8], ecx
// 0070f12c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0070f130  894a0c               mov dword ptr [edx + 0xc], ecx
// 0070f133  56                   push esi
// 0070f134  8bc8                 mov ecx, eax
// 0070f136  e8f5b0ffff           call 0x70a230
// 0070f13b  8bc6                 mov eax, esi
// 0070f13d  5e                   pop esi
// 0070f13e  59                   pop ecx
// 0070f13f  c21400               ret 0x14

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
