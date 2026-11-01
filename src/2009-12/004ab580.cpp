// from server: 100% by auto
// roc 2009-12 004ab580  unit: Ogre::RbxSceneUpdater  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ab580
//
// 004ab580  83ec08               sub esp, 8
// 004ab583  53                   push ebx
// 004ab584  55                   push ebp
// 004ab585  56                   push esi
// 004ab586  8bf1                 mov esi, ecx
// 004ab588  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004ab58b  57                   push edi
// 004ab58c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004ab58f  7606                 jbe 0x4ab597
// 004ab591  ff1560b79800         call dword ptr [0x98b760]
// 004ab597  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004ab59a  8b2e                 mov ebp, dword ptr [esi]
// 004ab59c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004ab59f  7606                 jbe 0x4ab5a7
// 004ab5a1  ff1560b79800         call dword ptr [0x98b760]
// 004ab5a7  8b06                 mov eax, dword ptr [esi]
// 004ab5a9  53                   push ebx
// 004ab5aa  55                   push ebp
// 004ab5ab  57                   push edi
// 004ab5ac  50                   push eax
// 004ab5ad  8d442420             lea eax, [esp + 0x20]
// 004ab5b1  50                   push eax
// 004ab5b2  8bce                 mov ecx, esi
// 004ab5b4  e887fdffff           call 0x4ab340
// 004ab5b9  5f                   pop edi
// 004ab5ba  5e                   pop esi
// 004ab5bb  5d                   pop ebp
// 004ab5bc  5b                   pop ebx
// 004ab5bd  83c408               add esp, 8
// 004ab5c0  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
