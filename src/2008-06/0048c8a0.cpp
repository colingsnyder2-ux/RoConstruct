// from server: 100% by auto
// roc 2008-06 0048c8a0  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048c8a0
//
// 0048c8a0  51                   push ecx
// 0048c8a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048c8a5  c6042400             mov byte ptr [esp], 0
// 0048c8a9  8b0424               mov eax, dword ptr [esp]
// 0048c8ac  50                   push eax
// 0048c8ad  8b442414             mov eax, dword ptr [esp + 0x14]
// 0048c8b1  52                   push edx
// 0048c8b2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048c8b6  83c108               add ecx, 8
// 0048c8b9  51                   push ecx
// 0048c8ba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048c8be  50                   push eax
// 0048c8bf  51                   push ecx
// 0048c8c0  52                   push edx
// 0048c8c1  e85aeeffff           call 0x48b720
// 0048c8c6  83c41c               add esp, 0x1c
// 0048c8c9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
