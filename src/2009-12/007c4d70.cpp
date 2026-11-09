// from server: 100% by nuck16
// roc 2009-12 007c4d70  unit: RBX::ChatOutput  size: 66 bytes
//
// 007c4d70  51                   push ecx
// 007c4d71  56                   push esi
// 007c4d72  c744240400000000     mov dword ptr [esp + 4], 0
// 007c4d7a  e801f7ffff           call 0x7c4480
// 007c4d7f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007c4d83  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007c4d87  83ec10               sub esp, 0x10
// 007c4d8a  8bd4                 mov edx, esp
// 007c4d8c  890a                 mov dword ptr [edx], ecx
// 007c4d8e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007c4d92  894a04               mov dword ptr [edx + 4], ecx
// 007c4d95  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c4d99  894a08               mov dword ptr [edx + 8], ecx
// 007c4d9c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007c4da0  894a0c               mov dword ptr [edx + 0xc], ecx
// 007c4da3  56                   push esi
// 007c4da4  8bc8                 mov ecx, eax
// 007c4da6  e8c5e5ffff           call 0x7c3370
// 007c4dab  8bc6                 mov eax, esi
// 007c4dad  5e                   pop esi
// 007c4dae  59                   pop ecx
// 007c4daf  c21400               ret 0x14

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
