// from server: 100% by auto
// roc 2010-06 0079e2b0  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0079e2b0
//
// 0079e2b0  51                   push ecx
// 0079e2b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0079e2b5  c6042400             mov byte ptr [esp], 0
// 0079e2b9  8b0424               mov eax, dword ptr [esp]
// 0079e2bc  50                   push eax
// 0079e2bd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0079e2c1  52                   push edx
// 0079e2c2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0079e2c6  83c108               add ecx, 8
// 0079e2c9  51                   push ecx
// 0079e2ca  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0079e2ce  50                   push eax
// 0079e2cf  51                   push ecx
// 0079e2d0  52                   push edx
// 0079e2d1  e81a1ae7ff           call 0x60fcf0
// 0079e2d6  83c41c               add esp, 0x1c
// 0079e2d9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
