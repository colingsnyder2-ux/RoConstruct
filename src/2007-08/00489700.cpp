// from server: 100% by auto
// roc 2007-08 00489700  unit: RBX::Network::VPlayer::?$FactoryProduct  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00489700
//
// 00489700  51                   push ecx
// 00489701  8b542410             mov edx, dword ptr [esp + 0x10]
// 00489705  c6042400             mov byte ptr [esp], 0
// 00489709  8b0424               mov eax, dword ptr [esp]
// 0048970c  50                   push eax
// 0048970d  8b442414             mov eax, dword ptr [esp + 0x14]
// 00489711  52                   push edx
// 00489712  8b542410             mov edx, dword ptr [esp + 0x10]
// 00489716  51                   push ecx
// 00489717  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048971b  50                   push eax
// 0048971c  51                   push ecx
// 0048971d  52                   push edx
// 0048971e  e88df1f9ff           call 0x4288b0
// 00489723  83c41c               add esp, 0x1c
// 00489726  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
