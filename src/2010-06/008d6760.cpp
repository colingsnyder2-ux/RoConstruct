// from server: 100% by auto
// roc 2010-06 008d6760  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d6760
//
// 008d6760  51                   push ecx
// 008d6761  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d6765  c6042400             mov byte ptr [esp], 0
// 008d6769  8b0424               mov eax, dword ptr [esp]
// 008d676c  50                   push eax
// 008d676d  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d6771  52                   push edx
// 008d6772  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d6776  83c108               add ecx, 8
// 008d6779  51                   push ecx
// 008d677a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008d677e  50                   push eax
// 008d677f  51                   push ecx
// 008d6780  52                   push edx
// 008d6781  e8faf5ffff           call 0x8d5d80
// 008d6786  83c41c               add esp, 0x1c
// 008d6789  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
