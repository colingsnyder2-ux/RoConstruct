// from server: 100% by nuck16
// roc 2009-12 0046f260  unit: CScriptEditor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0046f260
//
// 0046f260  51                   push ecx
// 0046f261  56                   push esi
// 0046f262  c744240400000000     mov dword ptr [esp + 4], 0
// 0046f26a  e88110fbff           call 0x4202f0
// 0046f26f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046f273  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046f277  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0046f27b  51                   push ecx
// 0046f27c  52                   push edx
// 0046f27d  56                   push esi
// 0046f27e  8bc8                 mov ecx, eax
// 0046f280  e89bf6ffff           call 0x46e920
// 0046f285  8bc6                 mov eax, esi
// 0046f287  5e                   pop esi
// 0046f288  59                   pop ecx
// 0046f289  c20c00               ret 0xc

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
