// from server: 100% by auto
// roc 2009-12 004b1e00  unit: Ogre::RbxTextureCompositorSceneManager  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b1e00
//
// 004b1e00  6aff                 push -1
// 004b1e02  68d8c59300           push 0x93c5d8
// 004b1e07  64a100000000         mov eax, dword ptr fs:[0]
// 004b1e0d  50                   push eax
// 004b1e0e  64892500000000       mov dword ptr fs:[0], esp
// 004b1e15  51                   push ecx
// 004b1e16  56                   push esi
// 004b1e17  8bf1                 mov esi, ecx
// 004b1e19  89742404             mov dword ptr [esp + 4], esi
// 004b1e1d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004b1e25  e8c6fdffff           call 0x4b1bf0
// 004b1e2a  8b06                 mov eax, dword ptr [esi]
// 004b1e2c  50                   push eax
// 004b1e2d  e8281a3400           call 0x7f385a
// 004b1e32  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b1e36  83c404               add esp, 4
// 004b1e39  5e                   pop esi
// 004b1e3a  64890d00000000       mov dword ptr fs:[0], ecx
// 004b1e41  83c410               add esp, 0x10
// 004b1e44  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
