// from server: 100% by auto
// roc 2009-12 004a30a0  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a30a0
//
// 004a30a0  51                   push ecx
// 004a30a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a30a5  c6042400             mov byte ptr [esp], 0
// 004a30a9  8b0424               mov eax, dword ptr [esp]
// 004a30ac  50                   push eax
// 004a30ad  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a30b1  52                   push edx
// 004a30b2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a30b6  83c108               add ecx, 8
// 004a30b9  51                   push ecx
// 004a30ba  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a30be  50                   push eax
// 004a30bf  51                   push ecx
// 004a30c0  52                   push edx
// 004a30c1  e8dadeffff           call 0x4a0fa0
// 004a30c6  83c41c               add esp, 0x1c
// 004a30c9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
