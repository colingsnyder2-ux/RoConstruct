// from server: 100% by nuck16
// roc 2009-12 00687090  unit: RBX::ChangeHistoryService  size: 66 bytes
//
// 00687090  51                   push ecx
// 00687091  56                   push esi
// 00687092  c744240400000000     mov dword ptr [esp + 4], 0
// 0068709a  e891b0feff           call 0x672130
// 0068709f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006870a3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006870a7  83ec10               sub esp, 0x10
// 006870aa  8bd4                 mov edx, esp
// 006870ac  890a                 mov dword ptr [edx], ecx
// 006870ae  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006870b2  894a04               mov dword ptr [edx + 4], ecx
// 006870b5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006870b9  894a08               mov dword ptr [edx + 8], ecx
// 006870bc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006870c0  894a0c               mov dword ptr [edx + 0xc], ecx
// 006870c3  56                   push esi
// 006870c4  8bc8                 mov ecx, eax
// 006870c6  e8a5e2ffff           call 0x685370
// 006870cb  8bc6                 mov eax, esi
// 006870cd  5e                   pop esi
// 006870ce  59                   pop ecx
// 006870cf  c21400               ret 0x14

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
