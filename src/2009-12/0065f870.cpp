// from server: 100% by nuck16
// roc 2009-12 0065f870  unit: RBX::ObjectValue  size: 80 bytes
//
// 0065f870  51                   push ecx
// 0065f871  56                   push esi
// 0065f872  c744240400000000     mov dword ptr [esp + 4], 0
// 0065f87a  e82124e6ff           call 0x4c1ca0
// 0065f87f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065f883  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0065f887  83ec18               sub esp, 0x18
// 0065f88a  8bd4                 mov edx, esp
// 0065f88c  890a                 mov dword ptr [edx], ecx
// 0065f88e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0065f892  894a04               mov dword ptr [edx + 4], ecx
// 0065f895  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0065f899  894a08               mov dword ptr [edx + 8], ecx
// 0065f89c  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0065f8a0  894a0c               mov dword ptr [edx + 0xc], ecx
// 0065f8a3  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0065f8a7  894a10               mov dword ptr [edx + 0x10], ecx
// 0065f8aa  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0065f8ae  894a14               mov dword ptr [edx + 0x14], ecx
// 0065f8b1  56                   push esi
// 0065f8b2  8bc8                 mov ecx, eax
// 0065f8b4  e8e7e1ffff           call 0x65daa0
// 0065f8b9  8bc6                 mov eax, esi
// 0065f8bb  5e                   pop esi
// 0065f8bc  59                   pop ecx
// 0065f8bd  c21c00               ret 0x1c

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
