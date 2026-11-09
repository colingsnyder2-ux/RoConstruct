// from server: 100% by auto
// roc 2008-06 004dd7a0  unit: RBX::RenderBase::Mesh::Level  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004dd7a0
//
// 004dd7a0  51                   push ecx
// 004dd7a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004dd7a5  c6042400             mov byte ptr [esp], 0
// 004dd7a9  8b0424               mov eax, dword ptr [esp]
// 004dd7ac  50                   push eax
// 004dd7ad  8b442414             mov eax, dword ptr [esp + 0x14]
// 004dd7b1  52                   push edx
// 004dd7b2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004dd7b6  83c108               add ecx, 8
// 004dd7b9  51                   push ecx
// 004dd7ba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004dd7be  50                   push eax
// 004dd7bf  51                   push ecx
// 004dd7c0  52                   push edx
// 004dd7c1  e8aaeeffff           call 0x4dc670
// 004dd7c6  83c41c               add esp, 0x1c
// 004dd7c9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
