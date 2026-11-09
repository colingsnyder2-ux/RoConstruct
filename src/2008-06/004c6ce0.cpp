// from server: 100% by auto
// roc 2008-06 004c6ce0  unit: ProfiledRakPeer  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c6ce0
//
// 004c6ce0  56                   push esi
// 004c6ce1  8bf1                 mov esi, ecx
// 004c6ce3  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c6ce6  2b460c               sub eax, dword ptr [esi + 0xc]
// 004c6ce9  57                   push edi
// 004c6cea  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004c6cee  c1f802               sar eax, 2
// 004c6cf1  3bf8                 cmp edi, eax
// 004c6cf3  7206                 jb 0x4c6cfb
// 004c6cf5  ff1590288000         call dword ptr [0x802890]
// 004c6cfb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004c6cfe  8d04b9               lea eax, [ecx + edi*4]
// 004c6d01  5f                   pop edi
// 004c6d02  5e                   pop esi
// 004c6d03  c20400               ret 4
// standard library vector<ptr> (function ??A?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
