// from server: 100% by auto
// roc 2010-06 008dd410  unit: Ogre::RbxMaterialAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008dd410
//
// 008dd410  51                   push ecx
// 008dd411  8b542410             mov edx, dword ptr [esp + 0x10]
// 008dd415  c6042400             mov byte ptr [esp], 0
// 008dd419  8b0424               mov eax, dword ptr [esp]
// 008dd41c  50                   push eax
// 008dd41d  8b442414             mov eax, dword ptr [esp + 0x14]
// 008dd421  52                   push edx
// 008dd422  8b542410             mov edx, dword ptr [esp + 0x10]
// 008dd426  83c108               add ecx, 8
// 008dd429  51                   push ecx
// 008dd42a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008dd42e  50                   push eax
// 008dd42f  51                   push ecx
// 008dd430  52                   push edx
// 008dd431  e85aeeffff           call 0x8dc290
// 008dd436  83c41c               add esp, 0x1c
// 008dd439  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
