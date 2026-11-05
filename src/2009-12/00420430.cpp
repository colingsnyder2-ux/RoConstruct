// from server: 100% by nuck16
// roc 2009-12 00420430  unit: CSelectionTreeCtrl  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00420430
//
// 00420430  51                   push ecx
// 00420431  56                   push esi
// 00420432  c744240400000000     mov dword ptr [esp + 4], 0
// 0042043a  e8b1feffff           call 0x4202f0
// 0042043f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00420443  8b542410             mov edx, dword ptr [esp + 0x10]
// 00420447  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0042044b  51                   push ecx
// 0042044c  52                   push edx
// 0042044d  56                   push esi
// 0042044e  8bc8                 mov ecx, eax
// 00420450  e8dbfbffff           call 0x420030
// 00420455  8bc6                 mov eax, esi
// 00420457  5e                   pop esi
// 00420458  59                   pop ecx
// 00420459  c20c00               ret 0xc

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
