// from server: 100% by auto
// roc 2008-06 00693ef0  unit: Ogre::RbxSceneManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00693ef0
//
// 00693ef0  51                   push ecx
// 00693ef1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00693ef5  c6042400             mov byte ptr [esp], 0
// 00693ef9  8b0424               mov eax, dword ptr [esp]
// 00693efc  50                   push eax
// 00693efd  8b442414             mov eax, dword ptr [esp + 0x14]
// 00693f01  52                   push edx
// 00693f02  8b542410             mov edx, dword ptr [esp + 0x10]
// 00693f06  83c108               add ecx, 8
// 00693f09  51                   push ecx
// 00693f0a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00693f0e  50                   push eax
// 00693f0f  51                   push ecx
// 00693f10  52                   push edx
// 00693f11  e88aa2ffff           call 0x68e1a0
// 00693f16  83c41c               add esp, 0x1c
// 00693f19  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
