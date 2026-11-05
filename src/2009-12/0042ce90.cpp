// from server: 100% by nuck16
// roc 2009-12 0042ce90  unit: RBX::$$A6AXVBrickColor::?$signal::slot  size: 73 bytes
//
// 0042ce90  51                   push ecx
// 0042ce91  56                   push esi
// 0042ce92  c744240400000000     mov dword ptr [esp + 4], 0
// 0042ce9a  e8d1f9ffff           call 0x42c870
// 0042ce9f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042cea3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0042cea7  83ec14               sub esp, 0x14
// 0042ceaa  8bd4                 mov edx, esp
// 0042ceac  890a                 mov dword ptr [edx], ecx
// 0042ceae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0042ceb2  894a04               mov dword ptr [edx + 4], ecx
// 0042ceb5  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0042ceb9  894a08               mov dword ptr [edx + 8], ecx
// 0042cebc  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0042cec0  894a0c               mov dword ptr [edx + 0xc], ecx
// 0042cec3  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0042cec7  894a10               mov dword ptr [edx + 0x10], ecx
// 0042ceca  56                   push esi
// 0042cecb  8bc8                 mov ecx, eax
// 0042cecd  e80ef5ffff           call 0x42c3e0
// 0042ced2  8bc6                 mov eax, esi
// 0042ced4  5e                   pop esi
// 0042ced5  59                   pop ecx
// 0042ced6  c21800               ret 0x18

struct Ret
{
    Ret(const Ret &);
    ~Ret();
    void *p;
};

struct Arg
{
    int f0, f1, f2, f3, f4;
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
