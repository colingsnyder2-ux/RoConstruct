// from server: 100% by auto
// roc 2010-06 008d6c20  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d6c20
//
// 008d6c20  83ec08               sub esp, 8
// 008d6c23  53                   push ebx
// 008d6c24  55                   push ebp
// 008d6c25  56                   push esi
// 008d6c26  8bf1                 mov esi, ecx
// 008d6c28  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008d6c2b  57                   push edi
// 008d6c2c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 008d6c2f  7606                 jbe 0x8d6c37
// 008d6c31  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d6c37  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008d6c3a  8b2e                 mov ebp, dword ptr [esi]
// 008d6c3c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 008d6c3f  7606                 jbe 0x8d6c47
// 008d6c41  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d6c47  8b06                 mov eax, dword ptr [esi]
// 008d6c49  53                   push ebx
// 008d6c4a  55                   push ebp
// 008d6c4b  57                   push edi
// 008d6c4c  50                   push eax
// 008d6c4d  8d442420             lea eax, [esp + 0x20]
// 008d6c51  50                   push eax
// 008d6c52  8bce                 mov ecx, esi
// 008d6c54  e837fbffff           call 0x8d6790
// 008d6c59  5f                   pop edi
// 008d6c5a  5e                   pop esi
// 008d6c5b  5d                   pop ebp
// 008d6c5c  5b                   pop ebx
// 008d6c5d  83c408               add esp, 8
// 008d6c60  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
