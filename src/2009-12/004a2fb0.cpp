// from server: 100% by auto
// roc 2009-12 004a2fb0  unit: Ogre::RbxMeshPartAdapter  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2fb0
//
// 004a2fb0  51                   push ecx
// 004a2fb1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2fb5  c6042400             mov byte ptr [esp], 0
// 004a2fb9  8b0424               mov eax, dword ptr [esp]
// 004a2fbc  50                   push eax
// 004a2fbd  8b442414             mov eax, dword ptr [esp + 0x14]
// 004a2fc1  52                   push edx
// 004a2fc2  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2fc6  83c108               add ecx, 8
// 004a2fc9  51                   push ecx
// 004a2fca  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a2fce  50                   push eax
// 004a2fcf  51                   push ecx
// 004a2fd0  52                   push edx
// 004a2fd1  e8fabaffff           call 0x49ead0
// 004a2fd6  83c41c               add esp, 0x1c
// 004a2fd9  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
