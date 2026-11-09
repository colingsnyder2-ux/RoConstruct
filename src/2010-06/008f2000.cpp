// from server: 100% by auto
// roc 2010-06 008f2000  unit: Ogre::RbxMeshPartAdapter  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f2000
//
// 008f2000  56                   push esi
// 008f2001  8bf1                 mov esi, ecx
// 008f2003  8b460c               mov eax, dword ptr [esi + 0xc]
// 008f2006  85c0                 test eax, eax
// 008f2008  7409                 je 0x8f2013
// 008f200a  50                   push eax
// 008f200b  e88a59ebff           call 0x7a799a
// 008f2010  83c404               add esp, 4
// 008f2013  8b06                 mov eax, dword ptr [esi]
// 008f2015  50                   push eax
// 008f2016  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 008f201d  c7461000000000       mov dword ptr [esi + 0x10], 0
// 008f2024  c7461400000000       mov dword ptr [esi + 0x14], 0
// 008f202b  e86a59ebff           call 0x7a799a
// 008f2030  83c404               add esp, 4
// 008f2033  5e                   pop esi
// 008f2034  c3                   ret 
// standard library vector<ptr> (function ??1?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
