// from server: 100% by auto
// roc 2009-06 0048cda0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048cda0
//
// 0048cda0  83ec08               sub esp, 8
// 0048cda3  53                   push ebx
// 0048cda4  55                   push ebp
// 0048cda5  56                   push esi
// 0048cda6  8bf1                 mov esi, ecx
// 0048cda8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0048cdab  57                   push edi
// 0048cdac  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0048cdaf  7606                 jbe 0x48cdb7
// 0048cdb1  ff15ace98900         call dword ptr [0x89e9ac]
// 0048cdb7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0048cdba  8b2e                 mov ebp, dword ptr [esi]
// 0048cdbc  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0048cdbf  7606                 jbe 0x48cdc7
// 0048cdc1  ff15ace98900         call dword ptr [0x89e9ac]
// 0048cdc7  8b06                 mov eax, dword ptr [esi]
// 0048cdc9  53                   push ebx
// 0048cdca  55                   push ebp
// 0048cdcb  57                   push edi
// 0048cdcc  50                   push eax
// 0048cdcd  8d442420             lea eax, [esp + 0x20]
// 0048cdd1  50                   push eax
// 0048cdd2  8bce                 mov ecx, esi
// 0048cdd4  e8e7fbffff           call 0x48c9c0
// 0048cdd9  5f                   pop edi
// 0048cdda  5e                   pop esi
// 0048cddb  5d                   pop ebp
// 0048cddc  5b                   pop ebx
// 0048cddd  83c408               add esp, 8
// 0048cde0  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
