// from server: 100% by auto
// roc 2009-12 004b1e50  unit: Ogre::RbxTextureCompositorSceneManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b1e50
//
// 004b1e50  51                   push ecx
// 004b1e51  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b1e55  c6042400             mov byte ptr [esp], 0
// 004b1e59  8b0424               mov eax, dword ptr [esp]
// 004b1e5c  50                   push eax
// 004b1e5d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004b1e61  52                   push edx
// 004b1e62  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b1e66  83c108               add ecx, 8
// 004b1e69  51                   push ecx
// 004b1e6a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b1e6e  50                   push eax
// 004b1e6f  51                   push ecx
// 004b1e70  52                   push edx
// 004b1e71  e88ae9ffff           call 0x4b0800
// 004b1e76  83c41c               add esp, 0x1c
// 004b1e79  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
