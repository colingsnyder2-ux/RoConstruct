// from server: 100% by nuck16
// roc 2009-12 007187d0  unit: RBX::$$A6AXPAVJoint::?$signal::slot  size: 66 bytes
//
// 007187d0  51                   push ecx
// 007187d1  56                   push esi
// 007187d2  c744240400000000     mov dword ptr [esp + 4], 0
// 007187da  e851ffffff           call 0x718730
// 007187df  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007187e3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007187e7  83ec10               sub esp, 0x10
// 007187ea  8bd4                 mov edx, esp
// 007187ec  890a                 mov dword ptr [edx], ecx
// 007187ee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007187f2  894a04               mov dword ptr [edx + 4], ecx
// 007187f5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007187f9  894a08               mov dword ptr [edx + 8], ecx
// 007187fc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00718800  894a0c               mov dword ptr [edx + 0xc], ecx
// 00718803  56                   push esi
// 00718804  8bc8                 mov ecx, eax
// 00718806  e8c5fdffff           call 0x7185d0
// 0071880b  8bc6                 mov eax, esi
// 0071880d  5e                   pop esi
// 0071880e  59                   pop ecx
// 0071880f  c21400               ret 0x14

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
