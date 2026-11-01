// from server: 100% by auto
// roc 2009-12 00444200  unit: RBX::RbxG3D::Material  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00444200
//
// 00444200  56                   push esi
// 00444201  8bf1                 mov esi, ecx
// 00444203  8b4610               mov eax, dword ptr [esi + 0x10]
// 00444206  2b460c               sub eax, dword ptr [esi + 0xc]
// 00444209  57                   push edi
// 0044420a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0044420e  c1f802               sar eax, 2
// 00444211  3bf8                 cmp edi, eax
// 00444213  7206                 jb 0x44421b
// 00444215  ff1560b79800         call dword ptr [0x98b760]
// 0044421b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0044421e  8d04b9               lea eax, [ecx + edi*4]
// 00444221  5f                   pop edi
// 00444222  5e                   pop esi
// 00444223  c20400               ret 4
// standard library vector<ptr> (function ??A?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
