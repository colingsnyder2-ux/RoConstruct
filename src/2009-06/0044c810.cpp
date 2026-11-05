// from server: 100% by auto
// roc 2009-06 0044c810  unit: CRobloxControlColorSelector  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044c810
//
// 0044c810  51                   push ecx
// 0044c811  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044c815  c6042400             mov byte ptr [esp], 0
// 0044c819  8b0424               mov eax, dword ptr [esp]
// 0044c81c  50                   push eax
// 0044c81d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044c821  52                   push edx
// 0044c822  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044c826  83c108               add ecx, 8
// 0044c829  51                   push ecx
// 0044c82a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044c82e  50                   push eax
// 0044c82f  51                   push ecx
// 0044c830  52                   push edx
// 0044c831  e8aafdffff           call 0x44c5e0
// 0044c836  83c41c               add esp, 0x1c
// 0044c839  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
