// from server: 100% by nuck16
// roc 2009-12 0074e6e0  unit: RBX::VArcHandles::?$EventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074e6e0
//
// 0074e6e0  51                   push ecx
// 0074e6e1  56                   push esi
// 0074e6e2  c744240400000000     mov dword ptr [esp + 4], 0
// 0074e6ea  e87127d1ff           call 0x460e60
// 0074e6ef  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0074e6f3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0074e6f7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0074e6fb  51                   push ecx
// 0074e6fc  52                   push edx
// 0074e6fd  56                   push esi
// 0074e6fe  8bc8                 mov ecx, eax
// 0074e700  e88bdeffff           call 0x74c590
// 0074e705  8bc6                 mov eax, esi
// 0074e707  5e                   pop esi
// 0074e708  59                   pop ecx
// 0074e709  c20c00               ret 0xc

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
