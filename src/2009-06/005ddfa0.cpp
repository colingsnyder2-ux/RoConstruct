// from server: 100% by auto
// roc 2009-06 005ddfa0  unit: RBX::VInstance::?$NonFactoryProduct  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ddfa0
//
// 005ddfa0  83ec08               sub esp, 8
// 005ddfa3  53                   push ebx
// 005ddfa4  55                   push ebp
// 005ddfa5  56                   push esi
// 005ddfa6  8bf1                 mov esi, ecx
// 005ddfa8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005ddfab  57                   push edi
// 005ddfac  395e0c               cmp dword ptr [esi + 0xc], ebx
// 005ddfaf  7606                 jbe 0x5ddfb7
// 005ddfb1  ff15ace98900         call dword ptr [0x89e9ac]
// 005ddfb7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 005ddfba  8b2e                 mov ebp, dword ptr [esi]
// 005ddfbc  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 005ddfbf  7606                 jbe 0x5ddfc7
// 005ddfc1  ff15ace98900         call dword ptr [0x89e9ac]
// 005ddfc7  8b06                 mov eax, dword ptr [esi]
// 005ddfc9  53                   push ebx
// 005ddfca  55                   push ebp
// 005ddfcb  57                   push edi
// 005ddfcc  50                   push eax
// 005ddfcd  8d442420             lea eax, [esp + 0x20]
// 005ddfd1  50                   push eax
// 005ddfd2  8bce                 mov ecx, esi
// 005ddfd4  e8d7fbffff           call 0x5ddbb0
// 005ddfd9  5f                   pop edi
// 005ddfda  5e                   pop esi
// 005ddfdb  5d                   pop ebp
// 005ddfdc  5b                   pop ebx
// 005ddfdd  83c408               add esp, 8
// 005ddfe0  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
