// from server: 100% by auto
// roc 2009-12 0048cea0  unit: G3D::Shader  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048cea0
//
// 0048cea0  51                   push ecx
// 0048cea1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048cea5  c6042400             mov byte ptr [esp], 0
// 0048cea9  8b0424               mov eax, dword ptr [esp]
// 0048ceac  50                   push eax
// 0048cead  8b442414             mov eax, dword ptr [esp + 0x14]
// 0048ceb1  52                   push edx
// 0048ceb2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048ceb6  83c108               add ecx, 8
// 0048ceb9  51                   push ecx
// 0048ceba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048cebe  50                   push eax
// 0048cebf  51                   push ecx
// 0048cec0  52                   push edx
// 0048cec1  e87af6ffff           call 0x48c540
// 0048cec6  83c41c               add esp, 0x1c
// 0048cec9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
