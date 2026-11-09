// from server: 100% by nuck16
// roc 2009-12 0074e6b0  unit: RBX::VArcHandles::?$EventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074e6b0
//
// 0074e6b0  51                   push ecx
// 0074e6b1  56                   push esi
// 0074e6b2  c744240400000000     mov dword ptr [esp + 4], 0
// 0074e6ba  e8a127d1ff           call 0x460e60
// 0074e6bf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0074e6c3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0074e6c7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0074e6cb  51                   push ecx
// 0074e6cc  52                   push edx
// 0074e6cd  56                   push esi
// 0074e6ce  8bc8                 mov ecx, eax
// 0074e6d0  e87bddffff           call 0x74c450
// 0074e6d5  8bc6                 mov eax, esi
// 0074e6d7  5e                   pop esi
// 0074e6d8  59                   pop ecx
// 0074e6d9  c20c00               ret 0xc

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
