// from server: 100% by auto
// roc 2009-06 005ddc40  unit: RBX::VInstance::?$NonFactoryProduct  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ddc40
//
// 005ddc40  51                   push ecx
// 005ddc41  8b542410             mov edx, dword ptr [esp + 0x10]
// 005ddc45  c6042400             mov byte ptr [esp], 0
// 005ddc49  8b0424               mov eax, dword ptr [esp]
// 005ddc4c  50                   push eax
// 005ddc4d  8b442414             mov eax, dword ptr [esp + 0x14]
// 005ddc51  52                   push edx
// 005ddc52  8b542410             mov edx, dword ptr [esp + 0x10]
// 005ddc56  83c108               add ecx, 8
// 005ddc59  51                   push ecx
// 005ddc5a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005ddc5e  50                   push eax
// 005ddc5f  51                   push ecx
// 005ddc60  52                   push edx
// 005ddc61  e82ae1ffff           call 0x5dbd90
// 005ddc66  83c41c               add esp, 0x1c
// 005ddc69  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
