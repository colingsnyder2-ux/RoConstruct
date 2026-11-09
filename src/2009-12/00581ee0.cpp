// from server: 100% by nuck16
// roc 2009-12 00581ee0  unit: RBX::SceneUpdater  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00581ee0
//
// 00581ee0  51                   push ecx
// 00581ee1  56                   push esi
// 00581ee2  c744240400000000     mov dword ptr [esp + 4], 0
// 00581eea  e821a7e9ff           call 0x41c610
// 00581eef  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00581ef3  8b542410             mov edx, dword ptr [esp + 0x10]
// 00581ef7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00581efb  51                   push ecx
// 00581efc  52                   push edx
// 00581efd  56                   push esi
// 00581efe  8bc8                 mov ecx, eax
// 00581f00  e89bd0ffff           call 0x57efa0
// 00581f05  8bc6                 mov eax, esi
// 00581f07  5e                   pop esi
// 00581f08  59                   pop ecx
// 00581f09  c20c00               ret 0xc

struct Ret
{
    Ret(const Ret &);
    ~Ret();
    void *p;
};

struct Impl
{
    Ret g(void *a0, void *a1);
};

struct Getter { static Impl *get(); };

struct S
{
    Ret f(void *a0, void *a1);
};

Ret S::f(void *a0, void *a1)
{
    Impl *impl = Getter::get();
    return impl->g(a0, a1);
}
