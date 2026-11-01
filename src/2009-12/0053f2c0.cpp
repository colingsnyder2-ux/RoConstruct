// from server: 100% by auto
// roc 2009-12 0053f2c0  unit: RBX::Network::Replicator::NewInstanceItem  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053f2c0
//
// 0053f2c0  51                   push ecx
// 0053f2c1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0053f2c5  c6042400             mov byte ptr [esp], 0
// 0053f2c9  8b0424               mov eax, dword ptr [esp]
// 0053f2cc  50                   push eax
// 0053f2cd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0053f2d1  52                   push edx
// 0053f2d2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0053f2d6  83c108               add ecx, 8
// 0053f2d9  51                   push ecx
// 0053f2da  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0053f2de  50                   push eax
// 0053f2df  51                   push ecx
// 0053f2e0  52                   push edx
// 0053f2e1  e86a6afcff           call 0x505d50
// 0053f2e6  83c41c               add esp, 0x1c
// 0053f2e9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
