// from server: 100% by auto
// roc 2010-06 008d9d60  unit: Ogre::RbxTextureCompositorSceneManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d9d60
//
// 008d9d60  51                   push ecx
// 008d9d61  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d9d65  c6042400             mov byte ptr [esp], 0
// 008d9d69  8b0424               mov eax, dword ptr [esp]
// 008d9d6c  50                   push eax
// 008d9d6d  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d9d71  52                   push edx
// 008d9d72  8b542410             mov edx, dword ptr [esp + 0x10]
// 008d9d76  83c108               add ecx, 8
// 008d9d79  51                   push ecx
// 008d9d7a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008d9d7e  50                   push eax
// 008d9d7f  51                   push ecx
// 008d9d80  52                   push edx
// 008d9d81  e8dae9ffff           call 0x8d8760
// 008d9d86  83c41c               add esp, 0x1c
// 008d9d89  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
