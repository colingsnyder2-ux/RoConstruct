// from server: 100% by nuck16
// roc 2009-12 007a49e0  unit: seg_007a0000  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007a49e0
//
// 007a49e0  51                   push ecx
// 007a49e1  56                   push esi
// 007a49e2  c744240400000000     mov dword ptr [esp + 4], 0
// 007a49ea  e8916eefff           call 0x69b880
// 007a49ef  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a49f3  8b542410             mov edx, dword ptr [esp + 0x10]
// 007a49f7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007a49fb  51                   push ecx
// 007a49fc  52                   push edx
// 007a49fd  56                   push esi
// 007a49fe  8bc8                 mov ecx, eax
// 007a4a00  e89bfeffff           call 0x7a48a0
// 007a4a05  8bc6                 mov eax, esi
// 007a4a07  5e                   pop esi
// 007a4a08  59                   pop ecx
// 007a4a09  c20c00               ret 0xc

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
