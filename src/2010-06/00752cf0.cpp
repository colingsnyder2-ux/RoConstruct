// from server: 100% by auto
// roc 2010-06 00752cf0  unit: RBX::PrismPoly  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00752cf0
//
// 00752cf0  56                   push esi
// 00752cf1  8bf1                 mov esi, ecx
// 00752cf3  8b4610               mov eax, dword ptr [esi + 0x10]
// 00752cf6  2b460c               sub eax, dword ptr [esi + 0xc]
// 00752cf9  57                   push edi
// 00752cfa  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00752cfe  c1f802               sar eax, 2
// 00752d01  3bf8                 cmp edi, eax
// 00752d03  7206                 jb 0x752d0b
// 00752d05  ff150ca99e00         call dword ptr [0x9ea90c]
// 00752d0b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00752d0e  8d04b9               lea eax, [ecx + edi*4]
// 00752d11  5f                   pop edi
// 00752d12  5e                   pop esi
// 00752d13  c20400               ret 4
// standard library vector<ptr> (function ??A?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
