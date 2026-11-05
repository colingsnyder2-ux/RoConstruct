// from server: 100% by auto
// roc 2007-08 0040faf0  unit: CopyVerb  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040faf0
//
// 0040faf0  56                   push esi
// 0040faf1  33c0                 xor eax, eax
// 0040faf3  57                   push edi
// 0040faf4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0040faf8  3bf8                 cmp edi, eax
// 0040fafa  8bf1                 mov esi, ecx
// 0040fafc  894604               mov dword ptr [esi + 4], eax
// 0040faff  894608               mov dword ptr [esi + 8], eax
// 0040fb02  89460c               mov dword ptr [esi + 0xc], eax
// 0040fb05  7507                 jne 0x40fb0e
// 0040fb07  5f                   pop edi
// 0040fb08  32c0                 xor al, al
// 0040fb0a  5e                   pop esi
// 0040fb0b  c20400               ret 4
// 0040fb0e  81ffffffff1f         cmp edi, 0x1fffffff
// 0040fb14  7605                 jbe 0x40fb1b
// 0040fb16  e8e57c0000           call 0x417800
// 0040fb1b  50                   push eax
// 0040fb1c  57                   push edi
// 0040fb1d  e89e7f1500           call 0x567ac0
// 0040fb22  894604               mov dword ptr [esi + 4], eax
// 0040fb25  894608               mov dword ptr [esi + 8], eax
// 0040fb28  83c408               add esp, 8
// 0040fb2b  8d04f8               lea eax, [eax + edi*8]
// 0040fb2e  89460c               mov dword ptr [esi + 0xc], eax
// 0040fb31  5f                   pop edi
// 0040fb32  b001                 mov al, 1
// 0040fb34  5e                   pop esi
// 0040fb35  c20400               ret 4
// standard library vector<double> (function ?_Buy@?$vector@NV?$allocator@N@std@@@std@@IAE_NI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
