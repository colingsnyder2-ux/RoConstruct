// from server: 100% by auto
// roc 2007-08 004f0f60  unit: RBX::Render::AggregatingSceneManager  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f0f60
//
// 004f0f60  51                   push ecx
// 004f0f61  8b542410             mov edx, dword ptr [esp + 0x10]
// 004f0f65  c6042400             mov byte ptr [esp], 0
// 004f0f69  8b0424               mov eax, dword ptr [esp]
// 004f0f6c  50                   push eax
// 004f0f6d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004f0f71  52                   push edx
// 004f0f72  8b542410             mov edx, dword ptr [esp + 0x10]
// 004f0f76  51                   push ecx
// 004f0f77  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004f0f7b  50                   push eax
// 004f0f7c  51                   push ecx
// 004f0f7d  52                   push edx
// 004f0f7e  e8fdebffff           call 0x4efb80
// 004f0f83  83c41c               add esp, 0x1c
// 004f0f86  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
