// from server: 100% by nuck16
// roc 2009-12 00460f10  unit: CRobloxView  size: 73 bytes
//
// 00460f10  51                   push ecx
// 00460f11  56                   push esi
// 00460f12  c744240400000000     mov dword ptr [esp + 4], 0
// 00460f1a  e841ffffff           call 0x460e60
// 00460f1f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00460f23  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00460f27  83ec14               sub esp, 0x14
// 00460f2a  8bd4                 mov edx, esp
// 00460f2c  890a                 mov dword ptr [edx], ecx
// 00460f2e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00460f32  894a04               mov dword ptr [edx + 4], ecx
// 00460f35  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00460f39  894a08               mov dword ptr [edx + 8], ecx
// 00460f3c  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00460f40  894a0c               mov dword ptr [edx + 0xc], ecx
// 00460f43  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00460f47  894a10               mov dword ptr [edx + 0x10], ecx
// 00460f4a  56                   push esi
// 00460f4b  8bc8                 mov ecx, eax
// 00460f4d  e89efaffff           call 0x4609f0
// 00460f52  8bc6                 mov eax, esi
// 00460f54  5e                   pop esi
// 00460f55  59                   pop ecx
// 00460f56  c21800               ret 0x18

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
