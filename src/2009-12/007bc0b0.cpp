// from server: 100% by auto
// roc 2009-12 007bc0b0  unit: RBX::SpatialFilter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007bc0b0
//
// 007bc0b0  51                   push ecx
// 007bc0b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007bc0b5  c6042400             mov byte ptr [esp], 0
// 007bc0b9  8b0424               mov eax, dword ptr [esp]
// 007bc0bc  50                   push eax
// 007bc0bd  8b442414             mov eax, dword ptr [esp + 0x14]
// 007bc0c1  52                   push edx
// 007bc0c2  8b542410             mov edx, dword ptr [esp + 0x10]
// 007bc0c6  83c108               add ecx, 8
// 007bc0c9  51                   push ecx
// 007bc0ca  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007bc0ce  50                   push eax
// 007bc0cf  51                   push ecx
// 007bc0d0  52                   push edx
// 007bc0d1  e84a14faff           call 0x75d520
// 007bc0d6  83c41c               add esp, 0x1c
// 007bc0d9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
