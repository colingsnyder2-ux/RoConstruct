// from server: 100% by auto
// roc 2010-06 008d8ba0  unit: Ogre::RbxTextureCompositorSceneManager  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d8ba0
//
// 008d8ba0  6aff                 push -1
// 008d8ba2  6858a29900           push 0x99a258
// 008d8ba7  64a100000000         mov eax, dword ptr fs:[0]
// 008d8bad  50                   push eax
// 008d8bae  64892500000000       mov dword ptr fs:[0], esp
// 008d8bb5  51                   push ecx
// 008d8bb6  56                   push esi
// 008d8bb7  8bf1                 mov esi, ecx
// 008d8bb9  89742404             mov dword ptr [esp + 4], esi
// 008d8bbd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008d8bc5  e826fdffff           call 0x8d88f0
// 008d8bca  8b06                 mov eax, dword ptr [esi]
// 008d8bcc  50                   push eax
// 008d8bcd  e8c8edecff           call 0x7a799a
// 008d8bd2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d8bd6  83c404               add esp, 4
// 008d8bd9  5e                   pop esi
// 008d8bda  64890d00000000       mov dword ptr fs:[0], ecx
// 008d8be1  83c410               add esp, 0x10
// 008d8be4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
