// from server: 100% by nuck16
// roc 2009-12 00470430  unit: CSelectionCaption  size: 66 bytes
//
// 00470430  51                   push ecx
// 00470431  56                   push esi
// 00470432  c744240400000000     mov dword ptr [esp + 4], 0
// 0047043a  e851fffaff           call 0x420390
// 0047043f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00470443  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00470447  83ec10               sub esp, 0x10
// 0047044a  8bd4                 mov edx, esp
// 0047044c  890a                 mov dword ptr [edx], ecx
// 0047044e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00470452  894a04               mov dword ptr [edx + 4], ecx
// 00470455  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00470459  894a08               mov dword ptr [edx + 8], ecx
// 0047045c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00470460  894a0c               mov dword ptr [edx + 0xc], ecx
// 00470463  56                   push esi
// 00470464  8bc8                 mov ecx, eax
// 00470466  e865feffff           call 0x4702d0
// 0047046b  8bc6                 mov eax, esi
// 0047046d  5e                   pop esi
// 0047046e  59                   pop ecx
// 0047046f  c21400               ret 0x14

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
