// from server: 100% by EspClaude
// roc 2009-06 00445c20  unit: CRbxPlayDocTemplate  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445c20
//
// 00445c20  56                   push esi
// 00445c21  8bf1                 mov esi, ecx
// 00445c23  8d8e94000000         lea ecx, [esi + 0x94]
// 00445c29  ff1510fd8900         call dword ptr [0x89fd10]
// 00445c2f  8bce                 mov ecx, esi
// 00445c31  e86e3a2d00           call 0x7196a4
// 00445c36  f644240801           test byte ptr [esp + 8], 1
// 00445c3b  7409                 je 0x445c46
// 00445c3d  56                   push esi
// 00445c3e  e8ef2d2d00           call 0x718a32
// 00445c43  83c404               add esp, 4
// 00445c46  8bc6                 mov eax, esi
// 00445c48  5e                   pop esi
// 00445c49  c20400               ret 4
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