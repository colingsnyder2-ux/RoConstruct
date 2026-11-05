// from server: 100% by auto
// roc 2009-06 0048f730  unit: Ogre::RbxTextureCompositorSceneManager  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048f730
//
// 0048f730  6aff                 push -1
// 0048f732  6878ef8600           push 0x86ef78
// 0048f737  64a100000000         mov eax, dword ptr fs:[0]
// 0048f73d  50                   push eax
// 0048f73e  64892500000000       mov dword ptr fs:[0], esp
// 0048f745  51                   push ecx
// 0048f746  56                   push esi
// 0048f747  8bf1                 mov esi, ecx
// 0048f749  89742404             mov dword ptr [esp + 4], esi
// 0048f74d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048f755  e806f4ffff           call 0x48eb60
// 0048f75a  8b06                 mov eax, dword ptr [esi]
// 0048f75c  50                   push eax
// 0048f75d  e8d0922800           call 0x718a32
// 0048f762  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0048f766  83c404               add esp, 4
// 0048f769  5e                   pop esi
// 0048f76a  64890d00000000       mov dword ptr fs:[0], ecx
// 0048f771  83c410               add esp, 0x10
// 0048f774  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
