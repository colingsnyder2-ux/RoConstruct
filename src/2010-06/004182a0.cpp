// from server: 100% by auto
// roc 2010-06 004182a0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004182a0
//
// 004182a0  56                   push esi
// 004182a1  8bf1                 mov esi, ecx
// 004182a3  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004182a6  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 004182a9  b893244992           mov eax, 0x92492493
// 004182ae  f7e9                 imul ecx
// 004182b0  03d1                 add edx, ecx
// 004182b2  c1fa04               sar edx, 4
// 004182b5  8bc2                 mov eax, edx
// 004182b7  c1e81f               shr eax, 0x1f
// 004182ba  57                   push edi
// 004182bb  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004182bf  03c2                 add eax, edx
// 004182c1  3bf8                 cmp edi, eax
// 004182c3  7206                 jb 0x4182cb
// 004182c5  ff150ca99e00         call dword ptr [0x9ea90c]
// 004182cb  8b560c               mov edx, dword ptr [esi + 0xc]
// 004182ce  8d0cfd00000000       lea ecx, [edi*8]
// 004182d5  2bcf                 sub ecx, edi
// 004182d7  5f                   pop edi
// 004182d8  8d048a               lea eax, [edx + ecx*4]
// 004182db  5e                   pop esi
// 004182dc  c20400               ret 4
// standard library vector<string> (function ??A?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@I@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
