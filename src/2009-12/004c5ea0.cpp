// from server: 100% by nuck16
// roc 2009-12 004c5ea0  unit: Ogre::RbxCluster  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c5ea0
//
// 004c5ea0  51                   push ecx
// 004c5ea1  56                   push esi
// 004c5ea2  c744240400000000     mov dword ptr [esp + 4], 0
// 004c5eaa  e8f1bdffff           call 0x4c1ca0
// 004c5eaf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004c5eb3  8b542410             mov edx, dword ptr [esp + 0x10]
// 004c5eb7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c5ebb  51                   push ecx
// 004c5ebc  52                   push edx
// 004c5ebd  56                   push esi
// 004c5ebe  8bc8                 mov ecx, eax
// 004c5ec0  e8bbeeffff           call 0x4c4d80
// 004c5ec5  8bc6                 mov eax, esi
// 004c5ec7  5e                   pop esi
// 004c5ec8  59                   pop ecx
// 004c5ec9  c20c00               ret 0xc

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
