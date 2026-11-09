// from server: 100% by nuck16
// roc 2009-12 00420e50  unit: CRobloxTreeCtrlNode  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00420e50
//
// 00420e50  51                   push ecx
// 00420e51  56                   push esi
// 00420e52  c744240400000000     mov dword ptr [esp + 4], 0
// 00420e5a  e8b1b7ffff           call 0x41c610
// 00420e5f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00420e63  8b542410             mov edx, dword ptr [esp + 0x10]
// 00420e67  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00420e6b  51                   push ecx
// 00420e6c  52                   push edx
// 00420e6d  56                   push esi
// 00420e6e  8bc8                 mov ecx, eax
// 00420e70  e89bfeffff           call 0x420d10
// 00420e75  8bc6                 mov eax, esi
// 00420e77  5e                   pop esi
// 00420e78  59                   pop ecx
// 00420e79  c20c00               ret 0xc

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
