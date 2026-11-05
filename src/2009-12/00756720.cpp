// from server: 100% by nuck16
// roc 2009-12 00756720  unit: RBX::VehicleSeat  size: 80 bytes
//
// 00756720  51                   push ecx
// 00756721  56                   push esi
// 00756722  c744240400000000     mov dword ptr [esp + 4], 0
// 0075672a  e8e15eccff           call 0x41c610
// 0075672f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00756733  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00756737  83ec18               sub esp, 0x18
// 0075673a  8bd4                 mov edx, esp
// 0075673c  890a                 mov dword ptr [edx], ecx
// 0075673e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00756742  894a04               mov dword ptr [edx + 4], ecx
// 00756745  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00756749  894a08               mov dword ptr [edx + 8], ecx
// 0075674c  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00756750  894a0c               mov dword ptr [edx + 0xc], ecx
// 00756753  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00756757  894a10               mov dword ptr [edx + 0x10], ecx
// 0075675a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0075675e  894a14               mov dword ptr [edx + 0x14], ecx
// 00756761  56                   push esi
// 00756762  8bc8                 mov ecx, eax
// 00756764  e847f5ffff           call 0x755cb0
// 00756769  8bc6                 mov eax, esi
// 0075676b  5e                   pop esi
// 0075676c  59                   pop ecx
// 0075676d  c21c00               ret 0x1c

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
