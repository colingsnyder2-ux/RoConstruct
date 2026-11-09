// from server: 100% by auto
// roc 2010-06 008d9d10  unit: Ogre::RbxTextureCompositorSceneManager  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d9d10
//
// 008d9d10  6aff                 push -1
// 008d9d12  6858a29900           push 0x99a258
// 008d9d17  64a100000000         mov eax, dword ptr fs:[0]
// 008d9d1d  50                   push eax
// 008d9d1e  64892500000000       mov dword ptr fs:[0], esp
// 008d9d25  51                   push ecx
// 008d9d26  56                   push esi
// 008d9d27  8bf1                 mov esi, ecx
// 008d9d29  89742404             mov dword ptr [esp + 4], esi
// 008d9d2d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008d9d35  e836feffff           call 0x8d9b70
// 008d9d3a  8b06                 mov eax, dword ptr [esi]
// 008d9d3c  50                   push eax
// 008d9d3d  e858dcecff           call 0x7a799a
// 008d9d42  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d9d46  83c404               add esp, 4
// 008d9d49  5e                   pop esi
// 008d9d4a  64890d00000000       mov dword ptr fs:[0], ecx
// 008d9d51  83c410               add esp, 0x10
// 008d9d54  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
