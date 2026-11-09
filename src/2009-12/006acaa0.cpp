// from server: 100% by nuck16
// roc 2009-12 006acaa0  unit: RBX::VHat::?$FactoryProduct  size: 80 bytes
//
// 006acaa0  51                   push ecx
// 006acaa1  56                   push esi
// 006acaa2  c744240400000000     mov dword ptr [esp + 4], 0
// 006acaaa  e861fbd6ff           call 0x41c610
// 006acaaf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006acab3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006acab7  83ec18               sub esp, 0x18
// 006acaba  8bd4                 mov edx, esp
// 006acabc  890a                 mov dword ptr [edx], ecx
// 006acabe  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006acac2  894a04               mov dword ptr [edx + 4], ecx
// 006acac5  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 006acac9  894a08               mov dword ptr [edx + 8], ecx
// 006acacc  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 006acad0  894a0c               mov dword ptr [edx + 0xc], ecx
// 006acad3  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 006acad7  894a10               mov dword ptr [edx + 0x10], ecx
// 006acada  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 006acade  894a14               mov dword ptr [edx + 0x14], ecx
// 006acae1  56                   push esi
// 006acae2  8bc8                 mov ecx, eax
// 006acae4  e8a7f2ffff           call 0x6abd90
// 006acae9  8bc6                 mov eax, esi
// 006acaeb  5e                   pop esi
// 006acaec  59                   pop ecx
// 006acaed  c21c00               ret 0x1c

struct Ret
{
    Ret(const Ret &);
    ~Ret();
    void *p;
};

struct Arg
{
    int f0, f1, f2, f3, f4, f5;
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
