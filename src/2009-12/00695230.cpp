// from server: 100% by nuck16
// roc 2009-12 00695230  unit: RBX::Tool  size: 66 bytes
//
// 00695230  51                   push ecx
// 00695231  56                   push esi
// 00695232  c744240400000000     mov dword ptr [esp + 4], 0
// 0069523a  e8d173d8ff           call 0x41c610
// 0069523f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00695243  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00695247  83ec10               sub esp, 0x10
// 0069524a  8bd4                 mov edx, esp
// 0069524c  890a                 mov dword ptr [edx], ecx
// 0069524e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00695252  894a04               mov dword ptr [edx + 4], ecx
// 00695255  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00695259  894a08               mov dword ptr [edx + 8], ecx
// 0069525c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00695260  894a0c               mov dword ptr [edx + 0xc], ecx
// 00695263  56                   push esi
// 00695264  8bc8                 mov ecx, eax
// 00695266  e895eaffff           call 0x693d00
// 0069526b  8bc6                 mov eax, esi
// 0069526d  5e                   pop esi
// 0069526e  59                   pop ecx
// 0069526f  c21400               ret 0x14

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
