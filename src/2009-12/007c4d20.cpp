// from server: 100% by nuck16
// roc 2009-12 007c4d20  unit: RBX::ChatOutput  size: 66 bytes
//
// 007c4d20  51                   push ecx
// 007c4d21  56                   push esi
// 007c4d22  c744240400000000     mov dword ptr [esp + 4], 0
// 007c4d2a  e8516bedff           call 0x69b880
// 007c4d2f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007c4d33  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007c4d37  83ec10               sub esp, 0x10
// 007c4d3a  8bd4                 mov edx, esp
// 007c4d3c  890a                 mov dword ptr [edx], ecx
// 007c4d3e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007c4d42  894a04               mov dword ptr [edx + 4], ecx
// 007c4d45  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c4d49  894a08               mov dword ptr [edx + 8], ecx
// 007c4d4c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007c4d50  894a0c               mov dword ptr [edx + 0xc], ecx
// 007c4d53  56                   push esi
// 007c4d54  8bc8                 mov ecx, eax
// 007c4d56  e8b5e4ffff           call 0x7c3210
// 007c4d5b  8bc6                 mov eax, esi
// 007c4d5d  5e                   pop esi
// 007c4d5e  59                   pop ecx
// 007c4d5f  c21400               ret 0x14

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
