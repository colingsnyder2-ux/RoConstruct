// from server: 100% by nuck16
// roc 2009-12 004c1d40  unit: RBX::VSparkles::?$FactoryProduct::Creator  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c1d40
//
// 004c1d40  51                   push ecx
// 004c1d41  56                   push esi
// 004c1d42  c744240400000000     mov dword ptr [esp + 4], 0
// 004c1d4a  e851ffffff           call 0x4c1ca0
// 004c1d4f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c1d53  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c1d57  83ec10               sub esp, 0x10
// 004c1d5a  8bd4                 mov edx, esp
// 004c1d5c  890a                 mov dword ptr [edx], ecx
// 004c1d5e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004c1d62  894a04               mov dword ptr [edx + 4], ecx
// 004c1d65  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004c1d69  894a08               mov dword ptr [edx + 8], ecx
// 004c1d6c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004c1d70  894a0c               mov dword ptr [edx + 0xc], ecx
// 004c1d73  56                   push esi
// 004c1d74  8bc8                 mov ecx, eax
// 004c1d76  e805fbffff           call 0x4c1880
// 004c1d7b  8bc6                 mov eax, esi
// 004c1d7d  5e                   pop esi
// 004c1d7e  59                   pop ecx
// 004c1d7f  c21400               ret 0x14

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
