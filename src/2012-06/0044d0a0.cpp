// from server: 100% by auto
// roc 2012-06 0044d0a0  unit: PasteVerb  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044d0a0
//
// 0044d0a0  56                   push esi
// 0044d0a1  8bf1                 mov esi, ecx
// 0044d0a3  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044d0a6  85c0                 test eax, eax
// 0044d0a8  7435                 je 0x44d0df
// 0044d0aa  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0044d0ad  8b5614               mov edx, dword ptr [esi + 0x14]
// 0044d0b0  8d4c08ff             lea ecx, [eax + ecx - 1]
// 0044d0b4  8bc1                 mov eax, ecx
// 0044d0b6  c1e804               shr eax, 4
// 0044d0b9  3bd0                 cmp edx, eax
// 0044d0bb  7702                 ja 0x44d0bf
// 0044d0bd  2bc2                 sub eax, edx
// 0044d0bf  8b5610               mov edx, dword ptr [esi + 0x10]
// 0044d0c2  83e10f               and ecx, 0xf
// 0044d0c5  030c82               add ecx, dword ptr [edx + eax*4]
// 0044d0c8  51                   push ecx
// 0044d0c9  8d4e0c               lea ecx, [esi + 0xc]
// 0044d0cc  ff152826b200         call dword ptr [0xb22628]
// 0044d0d2  83461cff             add dword ptr [esi + 0x1c], -1
// 0044d0d6  7507                 jne 0x44d0df
// 0044d0d8  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0044d0df  5e                   pop esi
// 0044d0e0  c3                   ret 
// standard library deque<char> (function ?pop_back@?$deque@DV?$allocator@D@std@@@std@@QAEXXZ)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
