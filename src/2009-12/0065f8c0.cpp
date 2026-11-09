// from server: 100% by nuck16
// roc 2009-12 0065f8c0  unit: RBX::ObjectValue  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0065f8c0
//
// 0065f8c0  51                   push ecx
// 0065f8c1  56                   push esi
// 0065f8c2  c744240400000000     mov dword ptr [esp + 4], 0
// 0065f8ca  e841cddbff           call 0x41c610
// 0065f8cf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065f8d3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0065f8d7  83ec18               sub esp, 0x18
// 0065f8da  8bd4                 mov edx, esp
// 0065f8dc  890a                 mov dword ptr [edx], ecx
// 0065f8de  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0065f8e2  894a04               mov dword ptr [edx + 4], ecx
// 0065f8e5  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0065f8e9  894a08               mov dword ptr [edx + 8], ecx
// 0065f8ec  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0065f8f0  894a0c               mov dword ptr [edx + 0xc], ecx
// 0065f8f3  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0065f8f7  894a10               mov dword ptr [edx + 0x10], ecx
// 0065f8fa  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0065f8fe  894a14               mov dword ptr [edx + 0x14], ecx
// 0065f901  56                   push esi
// 0065f902  8bc8                 mov ecx, eax
// 0065f904  e807e3ffff           call 0x65dc10
// 0065f909  8bc6                 mov eax, esi
// 0065f90b  5e                   pop esi
// 0065f90c  59                   pop ecx
// 0065f90d  c21c00               ret 0x1c

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
