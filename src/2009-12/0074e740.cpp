// from server: 100% by nuck16
// roc 2009-12 0074e740  unit: RBX::VArcHandles::?$EventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074e740
//
// 0074e740  51                   push ecx
// 0074e741  56                   push esi
// 0074e742  c744240400000000     mov dword ptr [esp + 4], 0
// 0074e74a  e891eaffff           call 0x74d1e0
// 0074e74f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0074e753  8b542410             mov edx, dword ptr [esp + 0x10]
// 0074e757  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0074e75b  51                   push ecx
// 0074e75c  52                   push edx
// 0074e75d  56                   push esi
// 0074e75e  8bc8                 mov ecx, eax
// 0074e760  e8abe0ffff           call 0x74c810
// 0074e765  8bc6                 mov eax, esi
// 0074e767  5e                   pop esi
// 0074e768  59                   pop ecx
// 0074e769  c20c00               ret 0xc

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
