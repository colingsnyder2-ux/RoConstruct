// from server: 100% by nuck16
// roc 2009-12 00751fe0  unit: RBX::LocalBackpack  size: 66 bytes
//
// 00751fe0  51                   push ecx
// 00751fe1  56                   push esi
// 00751fe2  c744240400000000     mov dword ptr [esp + 4], 0
// 00751fea  e821a6ccff           call 0x41c610
// 00751fef  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00751ff3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00751ff7  83ec10               sub esp, 0x10
// 00751ffa  8bd4                 mov edx, esp
// 00751ffc  890a                 mov dword ptr [edx], ecx
// 00751ffe  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00752002  894a04               mov dword ptr [edx + 4], ecx
// 00752005  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00752009  894a08               mov dword ptr [edx + 8], ecx
// 0075200c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00752010  894a0c               mov dword ptr [edx + 0xc], ecx
// 00752013  56                   push esi
// 00752014  8bc8                 mov ecx, eax
// 00752016  e8c5eeffff           call 0x750ee0
// 0075201b  8bc6                 mov eax, esi
// 0075201d  5e                   pop esi
// 0075201e  59                   pop ecx
// 0075201f  c21400               ret 0x14

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
