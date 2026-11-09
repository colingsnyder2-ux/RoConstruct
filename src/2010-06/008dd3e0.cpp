// from server: 100% by auto
// roc 2010-06 008dd3e0  unit: Ogre::RbxMaterialAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008dd3e0
//
// 008dd3e0  51                   push ecx
// 008dd3e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 008dd3e5  c6042400             mov byte ptr [esp], 0
// 008dd3e9  8b0424               mov eax, dword ptr [esp]
// 008dd3ec  50                   push eax
// 008dd3ed  8b442414             mov eax, dword ptr [esp + 0x14]
// 008dd3f1  52                   push edx
// 008dd3f2  8b542410             mov edx, dword ptr [esp + 0x10]
// 008dd3f6  83c108               add ecx, 8
// 008dd3f9  51                   push ecx
// 008dd3fa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008dd3fe  50                   push eax
// 008dd3ff  51                   push ecx
// 008dd400  52                   push edx
// 008dd401  e80a8effff           call 0x8d6210
// 008dd406  83c41c               add esp, 0x1c
// 008dd409  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
