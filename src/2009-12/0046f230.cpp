// from server: 100% by nuck16
// roc 2009-12 0046f230  unit: CScriptEditor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0046f230
//
// 0046f230  51                   push ecx
// 0046f231  56                   push esi
// 0046f232  c744240400000000     mov dword ptr [esp + 4], 0
// 0046f23a  e841ffffff           call 0x46f180
// 0046f23f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046f243  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046f247  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0046f24b  51                   push ecx
// 0046f24c  52                   push edx
// 0046f24d  56                   push esi
// 0046f24e  8bc8                 mov ecx, eax
// 0046f250  e88bf5ffff           call 0x46e7e0
// 0046f255  8bc6                 mov eax, esi
// 0046f257  5e                   pop esi
// 0046f258  59                   pop ecx
// 0046f259  c20c00               ret 0xc

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
