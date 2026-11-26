// from server: 100% by Xemicl
// roc 2012-06 0046dde0  unit: CRbxPlayDocTemplate  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046dde0
//
// 0046dde0  56                   push esi
// 0046dde1  8bf1                 mov esi, ecx
// 0046dde3  8d8e94000000         lea ecx, [esi + 0x94]
// 0046dde9  ff15d047b200         call dword ptr [0xb247d0]
// 0046ddef  8bce                 mov ecx, esi
// 0046ddf1  e8664f5100           call 0x982d5c
// 0046ddf6  f644240801           test byte ptr [esp + 8], 1
// 0046ddfb  7409                 je 0x46de06
// 0046ddfd  56                   push esi
// 0046ddfe  e811435100           call 0x982114
// 0046de03  83c404               add esp, 4
// 0046de06  8bc6                 mov eax, esi
// 0046de08  5e                   pop esi
// 0046de09  c20400               ret 4
// copied from an identical function in another client (function ?f@S@@QAEPAU1@I@Z)

typedef void (__thiscall *CleanupFunction)(void *);
extern CleanupFunction cleanup;

void __cdecl operator delete(void *);

struct S {
    void destroy();
    S *f(unsigned int flags);
};

S *S::f(unsigned int flags)
{
    cleanup(reinterpret_cast<char *>(this) + 0x94);
    destroy();
    if (flags & 1)
        operator delete(this);
    return this;
}