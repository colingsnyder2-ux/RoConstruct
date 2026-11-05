// from server: 100% by auto
// roc 2009-12 00443380  unit: RBX::MergeBinder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00443380
//
// 00443380  51                   push ecx
// 00443381  8b542410             mov edx, dword ptr [esp + 0x10]
// 00443385  c6042400             mov byte ptr [esp], 0
// 00443389  8b0424               mov eax, dword ptr [esp]
// 0044338c  50                   push eax
// 0044338d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00443391  52                   push edx
// 00443392  8b542410             mov edx, dword ptr [esp + 0x10]
// 00443396  83c108               add ecx, 8
// 00443399  51                   push ecx
// 0044339a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044339e  50                   push eax
// 0044339f  51                   push ecx
// 004433a0  52                   push edx
// 004433a1  e8aafeffff           call 0x443250
// 004433a6  83c41c               add esp, 0x1c
// 004433a9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
