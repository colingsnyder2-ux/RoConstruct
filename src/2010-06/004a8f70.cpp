// from server: 100% by auto
// roc 2010-06 004a8f70  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004a8f70
//
// 004a8f70  51                   push ecx
// 004a8f71  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a8f75  c6042400             mov byte ptr [esp], 0
// 004a8f79  8b0424               mov eax, dword ptr [esp]
// 004a8f7c  50                   push eax
// 004a8f7d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a8f81  52                   push edx
// 004a8f82  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a8f86  83c108               add ecx, 8
// 004a8f89  51                   push ecx
// 004a8f8a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a8f8e  50                   push eax
// 004a8f8f  51                   push ecx
// 004a8f90  52                   push edx
// 004a8f91  e86ab8f7ff           call 0x424800
// 004a8f96  83c41c               add esp, 0x1c
// 004a8f99  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
