// from server: 100% by auto
// roc 2008-06 00413b90  unit: CopyVerb  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00413b90
//
// 00413b90  56                   push esi
// 00413b91  33c0                 xor eax, eax
// 00413b93  57                   push edi
// 00413b94  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00413b98  8bf1                 mov esi, ecx
// 00413b9a  89460c               mov dword ptr [esi + 0xc], eax
// 00413b9d  894610               mov dword ptr [esi + 0x10], eax
// 00413ba0  894614               mov dword ptr [esi + 0x14], eax
// 00413ba3  3bf8                 cmp edi, eax
// 00413ba5  7507                 jne 0x413bae
// 00413ba7  5f                   pop edi
// 00413ba8  32c0                 xor al, al
// 00413baa  5e                   pop esi
// 00413bab  c20400               ret 4
// 00413bae  81ffffffff1f         cmp edi, 0x1fffffff
// 00413bb4  7605                 jbe 0x413bbb
// 00413bb6  e885310b00           call 0x4c6d40
// 00413bbb  50                   push eax
// 00413bbc  57                   push edi
// 00413bbd  e87ec12500           call 0x66fd40
// 00413bc2  89460c               mov dword ptr [esi + 0xc], eax
// 00413bc5  894610               mov dword ptr [esi + 0x10], eax
// 00413bc8  83c408               add esp, 8
// 00413bcb  8d04f8               lea eax, [eax + edi*8]
// 00413bce  894614               mov dword ptr [esi + 0x14], eax
// 00413bd1  5f                   pop edi
// 00413bd2  b001                 mov al, 1
// 00413bd4  5e                   pop esi
// 00413bd5  c20400               ret 4
// standard library vector<double> (function ?_Buy@?$vector@NV?$allocator@N@std@@@std@@IAE_NI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
