// from server: 100% by auto
// roc 2009-06 00418000  unit: RBX::VTool::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00418000
//
// 00418000  56                   push esi
// 00418001  8b7110               mov esi, dword ptr [ecx + 0x10]
// 00418004  2b710c               sub esi, dword ptr [ecx + 0xc]
// 00418007  b893244992           mov eax, 0x92492493
// 0041800c  f7ee                 imul esi
// 0041800e  03d6                 add edx, esi
// 00418010  c1fa04               sar edx, 4
// 00418013  8bc2                 mov eax, edx
// 00418015  c1e81f               shr eax, 0x1f
// 00418018  03c2                 add eax, edx
// 0041801a  5e                   pop esi
// 0041801b  c3                   ret 
// standard library vector<string> (function ?size@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QBEIXZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
