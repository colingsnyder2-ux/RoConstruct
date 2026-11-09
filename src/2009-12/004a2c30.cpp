// from server: 100% by auto
// roc 2009-12 004a2c30  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2c30
//
// 004a2c30  51                   push ecx
// 004a2c31  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2c35  c6042400             mov byte ptr [esp], 0
// 004a2c39  8b0424               mov eax, dword ptr [esp]
// 004a2c3c  50                   push eax
// 004a2c3d  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a2c41  52                   push edx
// 004a2c42  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2c46  83c108               add ecx, 8
// 004a2c49  51                   push ecx
// 004a2c4a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a2c4e  50                   push eax
// 004a2c4f  51                   push ecx
// 004a2c50  52                   push edx
// 004a2c51  e86af1ffff           call 0x4a1dc0
// 004a2c56  83c41c               add esp, 0x1c
// 004a2c59  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
