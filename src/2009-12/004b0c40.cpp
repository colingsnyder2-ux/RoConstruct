// from server: 100% by auto
// roc 2009-12 004b0c40  unit: Ogre::RbxTextureCompositorSceneManager  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b0c40
//
// 004b0c40  6aff                 push -1
// 004b0c42  68d8c59300           push 0x93c5d8
// 004b0c47  64a100000000         mov eax, dword ptr fs:[0]
// 004b0c4d  50                   push eax
// 004b0c4e  64892500000000       mov dword ptr fs:[0], esp
// 004b0c55  51                   push ecx
// 004b0c56  56                   push esi
// 004b0c57  8bf1                 mov esi, ecx
// 004b0c59  89742404             mov dword ptr [esp + 4], esi
// 004b0c5d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004b0c65  e806fdffff           call 0x4b0970
// 004b0c6a  8b06                 mov eax, dword ptr [esi]
// 004b0c6c  50                   push eax
// 004b0c6d  e8e82b3400           call 0x7f385a
// 004b0c72  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b0c76  83c404               add esp, 4
// 004b0c79  5e                   pop esi
// 004b0c7a  64890d00000000       mov dword ptr fs:[0], ecx
// 004b0c81  83c410               add esp, 0x10
// 004b0c84  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
