// from server: 100% by nuck16
// roc 2009-12 00460f60  unit: CRobloxView  size: 66 bytes
//
// 00460f60  51                   push ecx
// 00460f61  56                   push esi
// 00460f62  c744240400000000     mov dword ptr [esp + 4], 0
// 00460f6a  e8a1b6fbff           call 0x41c610
// 00460f6f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00460f73  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00460f77  83ec10               sub esp, 0x10
// 00460f7a  8bd4                 mov edx, esp
// 00460f7c  890a                 mov dword ptr [edx], ecx
// 00460f7e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00460f82  894a04               mov dword ptr [edx + 4], ecx
// 00460f85  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00460f89  894a08               mov dword ptr [edx + 8], ecx
// 00460f8c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00460f90  894a0c               mov dword ptr [edx + 0xc], ecx
// 00460f93  56                   push esi
// 00460f94  8bc8                 mov ecx, eax
// 00460f96  e8b5fbffff           call 0x460b50
// 00460f9b  8bc6                 mov eax, esi
// 00460f9d  5e                   pop esi
// 00460f9e  59                   pop ecx
// 00460f9f  c21400               ret 0x14

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
