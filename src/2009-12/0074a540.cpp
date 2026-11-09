// from server: 100% by nuck16
// roc 2009-12 0074a540  unit: RBX::VHandles::?$EventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074a540
//
// 0074a540  51                   push ecx
// 0074a541  56                   push esi
// 0074a542  c744240400000000     mov dword ptr [esp + 4], 0
// 0074a54a  e81169d1ff           call 0x460e60
// 0074a54f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0074a553  8b542410             mov edx, dword ptr [esp + 0x10]
// 0074a557  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0074a55b  51                   push ecx
// 0074a55c  52                   push edx
// 0074a55d  56                   push esi
// 0074a55e  8bc8                 mov ecx, eax
// 0074a560  e84bdfffff           call 0x7484b0
// 0074a565  8bc6                 mov eax, esi
// 0074a567  5e                   pop esi
// 0074a568  59                   pop ecx
// 0074a569  c20c00               ret 0xc

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
