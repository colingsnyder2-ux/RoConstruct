// from server: 100% by auto
// roc 2009-12 0049b1e0  unit: Ogre::RbxMeshPartAdapter::??fillVertices::?L::FileLoader  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0049b1e0
//
// 0049b1e0  56                   push esi
// 0049b1e1  8bf1                 mov esi, ecx
// 0049b1e3  8b460c               mov eax, dword ptr [esi + 0xc]
// 0049b1e6  85c0                 test eax, eax
// 0049b1e8  7409                 je 0x49b1f3
// 0049b1ea  50                   push eax
// 0049b1eb  e86a863500           call 0x7f385a
// 0049b1f0  83c404               add esp, 4
// 0049b1f3  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0049b1fa  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0049b201  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0049b208  5e                   pop esi
// 0049b209  c3                   ret 
// standard library vector<ptr> (function ?_Tidy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
