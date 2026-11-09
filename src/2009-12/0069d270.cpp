// from server: 100% by nuck16
// roc 2009-12 0069d270  unit: RBX::VWorkspace::?$BoundFuncDesc  size: 80 bytes
//
// 0069d270  51                   push ecx
// 0069d271  56                   push esi
// 0069d272  c744240400000000     mov dword ptr [esp + 4], 0
// 0069d27a  e801e6ffff           call 0x69b880
// 0069d27f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0069d283  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0069d287  83ec18               sub esp, 0x18
// 0069d28a  8bd4                 mov edx, esp
// 0069d28c  890a                 mov dword ptr [edx], ecx
// 0069d28e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0069d292  894a04               mov dword ptr [edx + 4], ecx
// 0069d295  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0069d299  894a08               mov dword ptr [edx + 8], ecx
// 0069d29c  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0069d2a0  894a0c               mov dword ptr [edx + 0xc], ecx
// 0069d2a3  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0069d2a7  894a10               mov dword ptr [edx + 0x10], ecx
// 0069d2aa  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0069d2ae  894a14               mov dword ptr [edx + 0x14], ecx
// 0069d2b1  56                   push esi
// 0069d2b2  8bc8                 mov ecx, eax
// 0069d2b4  e8e7beffff           call 0x6991a0
// 0069d2b9  8bc6                 mov eax, esi
// 0069d2bb  5e                   pop esi
// 0069d2bc  59                   pop ecx
// 0069d2bd  c21c00               ret 0x1c

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
