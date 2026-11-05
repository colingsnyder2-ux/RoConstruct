// from server: 100% by nuck16
// roc 2009-12 00440d80  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00440d80
//
// 00440d80  51                   push ecx
// 00440d81  56                   push esi
// 00440d82  c744240400000000     mov dword ptr [esp + 4], 0
// 00440d8a  e801f6fdff           call 0x420390
// 00440d8f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00440d93  8b542410             mov edx, dword ptr [esp + 0x10]
// 00440d97  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00440d9b  51                   push ecx
// 00440d9c  52                   push edx
// 00440d9d  56                   push esi
// 00440d9e  8bc8                 mov ecx, eax
// 00440da0  e8ebe3ffff           call 0x43f190
// 00440da5  8bc6                 mov eax, esi
// 00440da7  5e                   pop esi
// 00440da8  59                   pop ecx
// 00440da9  c20c00               ret 0xc

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
