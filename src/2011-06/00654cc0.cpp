// from server: 100% by Yeetserama
// roc 2011-06 00654cc0  unit: boost::Vthread::?$sp_counted_impl_p  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00654cc0
//
// 00654cc0  51                   push ecx
// 00654cc1  56                   push esi
// 00654cc2  68903e6500           push 0x653e90
// 00654cc7  68a0d5cc00           push 0xccd5a0
// 00654ccc  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00654cd4  e837c9daff           call 0x401610
// 00654cd9  8b742414             mov esi, dword ptr [esp + 0x14]
// 00654cdd  83c408               add esp, 8
// 00654ce0  6808d5cc00           push 0xccd508
// 00654ce5  8bce                 mov ecx, esi
// 00654ce7  ff15c804a400         call dword ptr [0xa404c8]
// 00654ced  8bc6                 mov eax, esi
// 00654cef  5e                   pop esi
// 00654cf0  59                   pop ecx
// 00654cf1  c3                   ret 
// copied from an identical function in another client (function ?construct@ns_ROCX00001d@@YAPAUS@1@PAU21@@Z)

namespace ns_ROCX00001d {
// from server: 100% by king_originala
struct S;

extern int guard;
extern S source;

extern void __cdecl callback();
extern void __cdecl initialize(void (__cdecl *)(), int *);

typedef S *(__thiscall *CopyFunction)(S *, const S &);
extern CopyFunction copyFunction;

S *__cdecl construct(S *destination)
{
    volatile int state = 0;
    initialize(callback, &guard);
    copyFunction(destination, source);
    return destination;
}
}
