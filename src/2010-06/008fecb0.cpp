// from server: 100% by auto
// roc 2010-06 008fecb0  unit: Ogre::RbxSceneUpdater  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fecb0
//
// 008fecb0  83ec08               sub esp, 8
// 008fecb3  53                   push ebx
// 008fecb4  55                   push ebp
// 008fecb5  56                   push esi
// 008fecb6  8bf1                 mov esi, ecx
// 008fecb8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008fecbb  57                   push edi
// 008fecbc  395e0c               cmp dword ptr [esi + 0xc], ebx
// 008fecbf  7606                 jbe 0x8fecc7
// 008fecc1  ff150ca99e00         call dword ptr [0x9ea90c]
// 008fecc7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008fecca  8b2e                 mov ebp, dword ptr [esi]
// 008feccc  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 008feccf  7606                 jbe 0x8fecd7
// 008fecd1  ff150ca99e00         call dword ptr [0x9ea90c]
// 008fecd7  8b06                 mov eax, dword ptr [esi]
// 008fecd9  53                   push ebx
// 008fecda  55                   push ebp
// 008fecdb  57                   push edi
// 008fecdc  50                   push eax
// 008fecdd  8d442420             lea eax, [esp + 0x20]
// 008fece1  50                   push eax
// 008fece2  8bce                 mov ecx, esi
// 008fece4  e8d7fdffff           call 0x8feac0
// 008fece9  5f                   pop edi
// 008fecea  5e                   pop esi
// 008feceb  5d                   pop ebp
// 008fecec  5b                   pop ebx
// 008feced  83c408               add esp, 8
// 008fecf0  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
