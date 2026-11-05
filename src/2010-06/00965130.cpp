// from server: 100% by auto
// roc 2010-06 00965130  unit: Ogre::RbxSceneUpdater  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00965130
//
// 00965130  6aff                 push -1
// 00965132  6858a29900           push 0x99a258
// 00965137  64a100000000         mov eax, dword ptr fs:[0]
// 0096513d  50                   push eax
// 0096513e  64892500000000       mov dword ptr fs:[0], esp
// 00965145  51                   push ecx
// 00965146  56                   push esi
// 00965147  8bf1                 mov esi, ecx
// 00965149  89742404             mov dword ptr [esp + 4], esi
// 0096514d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00965155  e8b6f0ffff           call 0x964210
// 0096515a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0096515d  50                   push eax
// 0096515e  e83728e4ff           call 0x7a799a
// 00965163  8b0e                 mov ecx, dword ptr [esi]
// 00965165  51                   push ecx
// 00965166  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0096516d  e82828e4ff           call 0x7a799a
// 00965172  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00965176  83c408               add esp, 8
// 00965179  5e                   pop esi
// 0096517a  64890d00000000       mov dword ptr fs:[0], ecx
// 00965181  83c410               add esp, 0x10
// 00965184  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
