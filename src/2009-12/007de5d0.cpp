// from server: 100% by nuck16
// roc 2009-12 007de5d0  unit: RBX::HUMAN::MovingNoPhysicsBase  size: 66 bytes
//
// 007de5d0  51                   push ecx
// 007de5d1  56                   push esi
// 007de5d2  c744240400000000     mov dword ptr [esp + 4], 0
// 007de5da  e8a10bc9ff           call 0x46f180
// 007de5df  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007de5e3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007de5e7  83ec10               sub esp, 0x10
// 007de5ea  8bd4                 mov edx, esp
// 007de5ec  890a                 mov dword ptr [edx], ecx
// 007de5ee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007de5f2  894a04               mov dword ptr [edx + 4], ecx
// 007de5f5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007de5f9  894a08               mov dword ptr [edx + 8], ecx
// 007de5fc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007de600  894a0c               mov dword ptr [edx + 0xc], ecx
// 007de603  56                   push esi
// 007de604  8bc8                 mov ecx, eax
// 007de606  e865feffff           call 0x7de470
// 007de60b  8bc6                 mov eax, esi
// 007de60d  5e                   pop esi
// 007de60e  59                   pop ecx
// 007de60f  c21400               ret 0x14

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
