// from server: 100% by auto
// roc 2008-06 0067fb10  unit: Ogre::RbxEntity  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067fb10
//
// 0067fb10  56                   push esi
// 0067fb11  8bf1                 mov esi, ecx
// 0067fb13  8b460c               mov eax, dword ptr [esi + 0xc]
// 0067fb16  85c0                 test eax, eax
// 0067fb18  7409                 je 0x67fb23
// 0067fb1a  50                   push eax
// 0067fb1b  e85a0b0200           call 0x6a067a
// 0067fb20  83c404               add esp, 4
// 0067fb23  8b06                 mov eax, dword ptr [esi]
// 0067fb25  50                   push eax
// 0067fb26  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 0067fb2d  c7461000000000       mov dword ptr [esi + 0x10], 0
// 0067fb34  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0067fb3b  e83a0b0200           call 0x6a067a
// 0067fb40  83c404               add esp, 4
// 0067fb43  5e                   pop esi
// 0067fb44  c3                   ret 
// standard library vector<ptr> (function ??1?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
