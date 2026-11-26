// from server: 100% by Xemicl
// roc 2012-06 007499c0  unit: boost::Vthread::?$sp_counted_impl_p  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007499c0
//
// 007499c0  51                   push ecx
// 007499c1  56                   push esi
// 007499c2  68908d7400           push 0x748d90
// 007499c7  68005ae300           push 0xe35a00
// 007499cc  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007499d4  e8c77bcbff           call 0x4015a0
// 007499d9  8b742414             mov esi, dword ptr [esp + 0x14]
// 007499dd  83c408               add esp, 8
// 007499e0  685859e300           push 0xe35958
// 007499e5  8bce                 mov ecx, esi
// 007499e7  ff154426b200         call dword ptr [0xb22644]
// 007499ed  8bc6                 mov eax, esi
// 007499ef  5e                   pop esi
// 007499f0  59                   pop ecx
// 007499f1  c3                   ret 
// copied from an identical function in another client (function ?construct@ns_ROCX000000@@YAPAUS@1@PAU21@@Z)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
// roc 2008-06 0055c4c0  unit: std::logic_error  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c4c0
//
// 0055c4c0  51                   push ecx
// 0055c4c1  56                   push esi
// 0055c4c2  68e43f9700           push 0x973fe4
// 0055c4c7  68e0c35500           push 0x55c3e0
// 0055c4cc  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0055c4d4  e857aeffff           call 0x557330
// 0055c4d9  8b742414             mov esi, dword ptr [esp + 0x14]
// 0055c4dd  83c408               add esp, 8
// 0055c4e0  68f0409700           push 0x9740f0
// 0055c4e5  8bce                 mov ecx, esi
// 0055c4e7  ff155c248000         call dword ptr [0x80245c]
// 0055c4ed  8bc6                 mov eax, esi
// 0055c4ef  5e                   pop esi
// 0055c4f0  59                   pop ecx
// 0055c4f1  c3                   ret 

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
