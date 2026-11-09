// from server: 100% by auto
// roc 2009-12 0048ced0  unit: G3D::Shader  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048ced0
//
// 0048ced0  51                   push ecx
// 0048ced1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048ced5  c6042400             mov byte ptr [esp], 0
// 0048ced9  8b0424               mov eax, dword ptr [esp]
// 0048cedc  50                   push eax
// 0048cedd  8b442414             mov eax, dword ptr [esp + 0x14]
// 0048cee1  52                   push edx
// 0048cee2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048cee6  83c108               add ecx, 8
// 0048cee9  51                   push ecx
// 0048ceea  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048ceee  50                   push eax
// 0048ceef  51                   push ecx
// 0048cef0  52                   push edx
// 0048cef1  e88af6ffff           call 0x48c580
// 0048cef6  83c41c               add esp, 0x1c
// 0048cef9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
