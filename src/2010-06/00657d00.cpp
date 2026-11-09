// from server: 100% by auto
// roc 2010-06 00657d00  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00657d00
//
// 00657d00  51                   push ecx
// 00657d01  8b542410             mov edx, dword ptr [esp + 0x10]
// 00657d05  c6042400             mov byte ptr [esp], 0
// 00657d09  8b0424               mov eax, dword ptr [esp]
// 00657d0c  50                   push eax
// 00657d0d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00657d11  52                   push edx
// 00657d12  8b542410             mov edx, dword ptr [esp + 0x10]
// 00657d16  83c108               add ecx, 8
// 00657d19  51                   push ecx
// 00657d1a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00657d1e  50                   push eax
// 00657d1f  51                   push ecx
// 00657d20  52                   push edx
// 00657d21  e80af8ffff           call 0x657530
// 00657d26  83c41c               add esp, 0x1c
// 00657d29  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
