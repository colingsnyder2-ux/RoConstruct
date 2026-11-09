// from server: 100% by nuck16
// roc 2009-12 00639ba0  unit: RBX::Selection  size: 66 bytes
//
// 00639ba0  51                   push ecx
// 00639ba1  56                   push esi
// 00639ba2  c744240400000000     mov dword ptr [esp + 4], 0
// 00639baa  e8d155e3ff           call 0x46f180
// 00639baf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00639bb3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00639bb7  83ec10               sub esp, 0x10
// 00639bba  8bd4                 mov edx, esp
// 00639bbc  890a                 mov dword ptr [edx], ecx
// 00639bbe  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00639bc2  894a04               mov dword ptr [edx + 4], ecx
// 00639bc5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00639bc9  894a08               mov dword ptr [edx + 8], ecx
// 00639bcc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00639bd0  894a0c               mov dword ptr [edx + 0xc], ecx
// 00639bd3  56                   push esi
// 00639bd4  8bc8                 mov ecx, eax
// 00639bd6  e8d5f2ffff           call 0x638eb0
// 00639bdb  8bc6                 mov eax, esi
// 00639bdd  5e                   pop esi
// 00639bde  59                   pop ecx
// 00639bdf  c21400               ret 0x14

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
