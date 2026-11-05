// from server: 100% by auto
// roc 2010-06 008d6820  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d6820
//
// 008d6820  6aff                 push -1
// 008d6822  6858a29900           push 0x99a258
// 008d6827  64a100000000         mov eax, dword ptr fs:[0]
// 008d682d  50                   push eax
// 008d682e  64892500000000       mov dword ptr fs:[0], esp
// 008d6835  51                   push ecx
// 008d6836  56                   push esi
// 008d6837  8bf1                 mov esi, ecx
// 008d6839  89742404             mov dword ptr [esp + 4], esi
// 008d683d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008d6845  e836feffff           call 0x8d6680
// 008d684a  8b06                 mov eax, dword ptr [esi]
// 008d684c  50                   push eax
// 008d684d  e84811edff           call 0x7a799a
// 008d6852  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d6856  83c404               add esp, 4
// 008d6859  5e                   pop esi
// 008d685a  64890d00000000       mov dword ptr fs:[0], ecx
// 008d6861  83c410               add esp, 0x10
// 008d6864  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
