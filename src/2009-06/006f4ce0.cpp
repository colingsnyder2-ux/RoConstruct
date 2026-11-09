// from server: 100% by auto
// roc 2009-06 006f4ce0  unit: RBX::HUMAN::GettingUp  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006f4ce0
//
// 006f4ce0  56                   push esi
// 006f4ce1  8bf1                 mov esi, ecx
// 006f4ce3  8b4610               mov eax, dword ptr [esi + 0x10]
// 006f4ce6  2b460c               sub eax, dword ptr [esi + 0xc]
// 006f4ce9  57                   push edi
// 006f4cea  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006f4cee  c1f802               sar eax, 2
// 006f4cf1  3bf8                 cmp edi, eax
// 006f4cf3  7206                 jb 0x6f4cfb
// 006f4cf5  ff15ace98900         call dword ptr [0x89e9ac]
// 006f4cfb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006f4cfe  8d04b9               lea eax, [ecx + edi*4]
// 006f4d01  5f                   pop edi
// 006f4d02  5e                   pop esi
// 006f4d03  c20400               ret 4
// standard library vector<ptr> (function ??A?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
