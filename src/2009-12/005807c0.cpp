// from server: 100% by auto
// roc 2009-12 005807c0  unit: Ogre::RbxSceneUpdater  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005807c0
//
// 005807c0  6aff                 push -1
// 005807c2  68d8c59300           push 0x93c5d8
// 005807c7  64a100000000         mov eax, dword ptr fs:[0]
// 005807cd  50                   push eax
// 005807ce  64892500000000       mov dword ptr fs:[0], esp
// 005807d5  51                   push ecx
// 005807d6  56                   push esi
// 005807d7  8bf1                 mov esi, ecx
// 005807d9  89742404             mov dword ptr [esp + 4], esi
// 005807dd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005807e5  e8b6f0ffff           call 0x57f8a0
// 005807ea  8b4614               mov eax, dword ptr [esi + 0x14]
// 005807ed  50                   push eax
// 005807ee  e867302700           call 0x7f385a
// 005807f3  8b0e                 mov ecx, dword ptr [esi]
// 005807f5  51                   push ecx
// 005807f6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 005807fd  e858302700           call 0x7f385a
// 00580802  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00580806  83c408               add esp, 8
// 00580809  5e                   pop esi
// 0058080a  64890d00000000       mov dword ptr fs:[0], ecx
// 00580811  83c410               add esp, 0x10
// 00580814  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
