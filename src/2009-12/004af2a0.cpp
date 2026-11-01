// from server: 100% by auto
// roc 2009-12 004af2a0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004af2a0
//
// 004af2a0  83ec08               sub esp, 8
// 004af2a3  53                   push ebx
// 004af2a4  55                   push ebp
// 004af2a5  56                   push esi
// 004af2a6  8bf1                 mov esi, ecx
// 004af2a8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004af2ab  57                   push edi
// 004af2ac  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004af2af  7606                 jbe 0x4af2b7
// 004af2b1  ff1560b79800         call dword ptr [0x98b760]
// 004af2b7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004af2ba  8b2e                 mov ebp, dword ptr [esi]
// 004af2bc  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004af2bf  7606                 jbe 0x4af2c7
// 004af2c1  ff1560b79800         call dword ptr [0x98b760]
// 004af2c7  8b06                 mov eax, dword ptr [esi]
// 004af2c9  53                   push ebx
// 004af2ca  55                   push ebp
// 004af2cb  57                   push edi
// 004af2cc  50                   push eax
// 004af2cd  8d442420             lea eax, [esp + 0x20]
// 004af2d1  50                   push eax
// 004af2d2  8bce                 mov ecx, esi
// 004af2d4  e8e7feffff           call 0x4af1c0
// 004af2d9  5f                   pop edi
// 004af2da  5e                   pop esi
// 004af2db  5d                   pop ebp
// 004af2dc  5b                   pop ebx
// 004af2dd  83c408               add esp, 8
// 004af2e0  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
