// from server: 100% by auto
// roc 2009-06 0048c990  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048c990
//
// 0048c990  51                   push ecx
// 0048c991  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048c995  c6042400             mov byte ptr [esp], 0
// 0048c999  8b0424               mov eax, dword ptr [esp]
// 0048c99c  50                   push eax
// 0048c99d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0048c9a1  52                   push edx
// 0048c9a2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048c9a6  83c108               add ecx, 8
// 0048c9a9  51                   push ecx
// 0048c9aa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048c9ae  50                   push eax
// 0048c9af  51                   push ecx
// 0048c9b0  52                   push edx
// 0048c9b1  e87afaffff           call 0x48c430
// 0048c9b6  83c41c               add esp, 0x1c
// 0048c9b9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
