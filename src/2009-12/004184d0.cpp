// from server: 100% by auto
// roc 2009-12 004184d0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004184d0
//
// 004184d0  56                   push esi
// 004184d1  8bf1                 mov esi, ecx
// 004184d3  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004184d6  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 004184d9  b893244992           mov eax, 0x92492493
// 004184de  f7e9                 imul ecx
// 004184e0  03d1                 add edx, ecx
// 004184e2  c1fa04               sar edx, 4
// 004184e5  8bc2                 mov eax, edx
// 004184e7  c1e81f               shr eax, 0x1f
// 004184ea  57                   push edi
// 004184eb  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004184ef  03c2                 add eax, edx
// 004184f1  3bf8                 cmp edi, eax
// 004184f3  7206                 jb 0x4184fb
// 004184f5  ff1560b79800         call dword ptr [0x98b760]
// 004184fb  8b560c               mov edx, dword ptr [esi + 0xc]
// 004184fe  8d0cfd00000000       lea ecx, [edi*8]
// 00418505  2bcf                 sub ecx, edi
// 00418507  5f                   pop edi
// 00418508  8d048a               lea eax, [edx + ecx*4]
// 0041850b  5e                   pop esi
// 0041850c  c20400               ret 4
// standard library vector<string> (function ??A?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@I@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
