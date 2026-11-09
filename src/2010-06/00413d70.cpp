// from server: 100% by auto
// roc 2010-06 00413d70  unit: CopyVerb  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413d70
//
// 00413d70  56                   push esi
// 00413d71  33c0                 xor eax, eax
// 00413d73  57                   push edi
// 00413d74  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00413d78  8bf1                 mov esi, ecx
// 00413d7a  89460c               mov dword ptr [esi + 0xc], eax
// 00413d7d  894610               mov dword ptr [esi + 0x10], eax
// 00413d80  894614               mov dword ptr [esi + 0x14], eax
// 00413d83  3bf8                 cmp edi, eax
// 00413d85  7507                 jne 0x413d8e
// 00413d87  5f                   pop edi
// 00413d88  32c0                 xor al, al
// 00413d8a  5e                   pop esi
// 00413d8b  c20400               ret 4
// 00413d8e  81ffffffff1f         cmp edi, 0x1fffffff
// 00413d94  7605                 jbe 0x413d9b
// 00413d96  e855000100           call 0x423df0
// 00413d9b  50                   push eax
// 00413d9c  57                   push edi
// 00413d9d  e80ea84e00           call 0x8fe5b0
// 00413da2  89460c               mov dword ptr [esi + 0xc], eax
// 00413da5  894610               mov dword ptr [esi + 0x10], eax
// 00413da8  83c408               add esp, 8
// 00413dab  8d04f8               lea eax, [eax + edi*8]
// 00413dae  894614               mov dword ptr [esi + 0x14], eax
// 00413db1  5f                   pop edi
// 00413db2  b001                 mov al, 1
// 00413db4  5e                   pop esi
// 00413db5  c20400               ret 4
// standard library vector<double> (function ?_Buy@?$vector@NV?$allocator@N@std@@@std@@IAE_NI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
