// from server: 100% by auto
// roc 2011-06 0093afe0  unit: Ogre::RbxTextureCompositorSceneManager  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0093afe0
//
// 0093afe0  6aff                 push -1
// 0093afe2  6868a39d00           push 0x9da368
// 0093afe7  64a100000000         mov eax, dword ptr fs:[0]
// 0093afed  50                   push eax
// 0093afee  64892500000000       mov dword ptr fs:[0], esp
// 0093aff5  51                   push ecx
// 0093aff6  56                   push esi
// 0093aff7  8bf1                 mov esi, ecx
// 0093aff9  89742404             mov dword ptr [esp + 4], esi
// 0093affd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0093b005  e8d6fcffff           call 0x93ace0
// 0093b00a  8b06                 mov eax, dword ptr [esi]
// 0093b00c  50                   push eax
// 0093b00d  e846f0ecff           call 0x80a058
// 0093b012  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0093b016  83c404               add esp, 4
// 0093b019  5e                   pop esi
// 0093b01a  64890d00000000       mov dword ptr fs:[0], ecx
// 0093b021  83c410               add esp, 0x10
// 0093b024  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
