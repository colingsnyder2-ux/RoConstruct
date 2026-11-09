// from server: 100% by auto
// roc 2009-06 004b7a00  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004b7a00
//
// 004b7a00  51                   push ecx
// 004b7a01  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b7a05  c6042400             mov byte ptr [esp], 0
// 004b7a09  8b0424               mov eax, dword ptr [esp]
// 004b7a0c  50                   push eax
// 004b7a0d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004b7a11  52                   push edx
// 004b7a12  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b7a16  83c108               add ecx, 8
// 004b7a19  51                   push ecx
// 004b7a1a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b7a1e  50                   push eax
// 004b7a1f  51                   push ecx
// 004b7a20  52                   push edx
// 004b7a21  e8dae3ffff           call 0x4b5e00
// 004b7a26  83c41c               add esp, 0x1c
// 004b7a29  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
