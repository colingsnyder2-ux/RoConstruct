// from server: 100% by auto
// roc 2009-06 00418020  unit: RBX::VTool::?$FactoryProduct::Creator  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00418020
//
// 00418020  56                   push esi
// 00418021  8bf1                 mov esi, ecx
// 00418023  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00418026  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00418029  b893244992           mov eax, 0x92492493
// 0041802e  f7e9                 imul ecx
// 00418030  03d1                 add edx, ecx
// 00418032  c1fa04               sar edx, 4
// 00418035  8bc2                 mov eax, edx
// 00418037  c1e81f               shr eax, 0x1f
// 0041803a  57                   push edi
// 0041803b  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0041803f  03c2                 add eax, edx
// 00418041  3bf8                 cmp edi, eax
// 00418043  7206                 jb 0x41804b
// 00418045  ff15ace98900         call dword ptr [0x89e9ac]
// 0041804b  8b560c               mov edx, dword ptr [esi + 0xc]
// 0041804e  8d0cfd00000000       lea ecx, [edi*8]
// 00418055  2bcf                 sub ecx, edi
// 00418057  5f                   pop edi
// 00418058  8d048a               lea eax, [edx + ecx*4]
// 0041805b  5e                   pop esi
// 0041805c  c20400               ret 4
// standard library vector<string> (function ??A?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@I@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
