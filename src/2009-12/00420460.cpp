// from server: 100% by nuck16
// roc 2009-12 00420460  unit: CSelectionTreeCtrl  size: 66 bytes
//
// 00420460  51                   push ecx
// 00420461  56                   push esi
// 00420462  c744240400000000     mov dword ptr [esp + 4], 0
// 0042046a  e821ffffff           call 0x420390
// 0042046f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00420473  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00420477  83ec10               sub esp, 0x10
// 0042047a  8bd4                 mov edx, esp
// 0042047c  890a                 mov dword ptr [edx], ecx
// 0042047e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00420482  894a04               mov dword ptr [edx + 4], ecx
// 00420485  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00420489  894a08               mov dword ptr [edx + 8], ecx
// 0042048c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00420490  894a0c               mov dword ptr [edx + 0xc], ecx
// 00420493  56                   push esi
// 00420494  8bc8                 mov ecx, eax
// 00420496  e8d5fcffff           call 0x420170
// 0042049b  8bc6                 mov eax, esi
// 0042049d  5e                   pop esi
// 0042049e  59                   pop ecx
// 0042049f  c21400               ret 0x14

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
