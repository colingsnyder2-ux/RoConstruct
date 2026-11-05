// from server: 100% by auto
// roc 2009-06 0047e170  unit: Ogre::RbxPart  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047e170
//
// 0047e170  83ec08               sub esp, 8
// 0047e173  53                   push ebx
// 0047e174  55                   push ebp
// 0047e175  56                   push esi
// 0047e176  8bf1                 mov esi, ecx
// 0047e178  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0047e17b  57                   push edi
// 0047e17c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0047e17f  7606                 jbe 0x47e187
// 0047e181  ff15ace98900         call dword ptr [0x89e9ac]
// 0047e187  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0047e18a  8b2e                 mov ebp, dword ptr [esi]
// 0047e18c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0047e18f  7606                 jbe 0x47e197
// 0047e191  ff15ace98900         call dword ptr [0x89e9ac]
// 0047e197  8b06                 mov eax, dword ptr [esi]
// 0047e199  53                   push ebx
// 0047e19a  55                   push ebp
// 0047e19b  57                   push edi
// 0047e19c  50                   push eax
// 0047e19d  8d442420             lea eax, [esp + 0x20]
// 0047e1a1  50                   push eax
// 0047e1a2  8bce                 mov ecx, esi
// 0047e1a4  e877002800           call 0x6fe220
// 0047e1a9  5f                   pop edi
// 0047e1aa  5e                   pop esi
// 0047e1ab  5d                   pop ebp
// 0047e1ac  5b                   pop ebx
// 0047e1ad  83c408               add esp, 8
// 0047e1b0  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
