// from server: 100% by auto
// roc 2009-12 004b2b90  unit: Ogre::RbxTextureCompositorSceneManager  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b2b90
//
// 004b2b90  6aff                 push -1
// 004b2b92  68d8c59300           push 0x93c5d8
// 004b2b97  64a100000000         mov eax, dword ptr fs:[0]
// 004b2b9d  50                   push eax
// 004b2b9e  64892500000000       mov dword ptr fs:[0], esp
// 004b2ba5  51                   push ecx
// 004b2ba6  56                   push esi
// 004b2ba7  8bf1                 mov esi, ecx
// 004b2ba9  89742404             mov dword ptr [esp + 4], esi
// 004b2bad  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004b2bb5  e886ffffff           call 0x4b2b40
// 004b2bba  8b06                 mov eax, dword ptr [esi]
// 004b2bbc  50                   push eax
// 004b2bbd  e8980c3400           call 0x7f385a
// 004b2bc2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b2bc6  83c404               add esp, 4
// 004b2bc9  5e                   pop esi
// 004b2bca  64890d00000000       mov dword ptr fs:[0], ecx
// 004b2bd1  83c410               add esp, 0x10
// 004b2bd4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
