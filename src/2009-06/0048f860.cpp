// from server: 100% by auto
// roc 2009-06 0048f860  unit: Ogre::RbxTextureCompositorSceneManager  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048f860
//
// 0048f860  51                   push ecx
// 0048f861  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048f865  c6042400             mov byte ptr [esp], 0
// 0048f869  8b0424               mov eax, dword ptr [esp]
// 0048f86c  50                   push eax
// 0048f86d  8b442414             mov eax, dword ptr [esp + 0x14]
// 0048f871  52                   push edx
// 0048f872  8b542410             mov edx, dword ptr [esp + 0x10]
// 0048f876  83c108               add ecx, 8
// 0048f879  51                   push ecx
// 0048f87a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048f87e  50                   push eax
// 0048f87f  51                   push ecx
// 0048f880  52                   push edx
// 0048f881  e8baebffff           call 0x48e440
// 0048f886  83c41c               add esp, 0x1c
// 0048f889  c20c00               ret 0xc
// standard library vector<string> (function ??$_Ucopy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@PAV21@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
