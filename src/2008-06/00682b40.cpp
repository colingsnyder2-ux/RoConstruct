// from server: 100% by auto
// roc 2008-06 00682b40  unit: Ogre::RbxSceneNode  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00682b40
//
// 00682b40  56                   push esi
// 00682b41  8bf1                 mov esi, ecx
// 00682b43  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00682b46  8b01                 mov eax, dword ptr [ecx]
// 00682b48  8909                 mov dword ptr [ecx], ecx
// 00682b4a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00682b4d  894904               mov dword ptr [ecx + 4], ecx
// 00682b50  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00682b57  3b4614               cmp eax, dword ptr [esi + 0x14]
// 00682b5a  7417                 je 0x682b73
// 00682b5c  57                   push edi
// 00682b5d  8d4900               lea ecx, [ecx]
// 00682b60  8b38                 mov edi, dword ptr [eax]
// 00682b62  50                   push eax
// 00682b63  e812db0100           call 0x6a067a
// 00682b68  83c404               add esp, 4
// 00682b6b  8bc7                 mov eax, edi
// 00682b6d  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 00682b70  75ee                 jne 0x682b60
// 00682b72  5f                   pop edi
// 00682b73  8b4614               mov eax, dword ptr [esi + 0x14]
// 00682b76  50                   push eax
// 00682b77  e8feda0100           call 0x6a067a
// 00682b7c  83c404               add esp, 4
// 00682b7f  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00682b86  5e                   pop esi
// 00682b87  c3                   ret 
// standard library list<ptr> (function ?_Tidy@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
