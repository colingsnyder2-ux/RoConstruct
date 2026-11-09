// from server: 100% by auto
// roc 2009-06 00476640  unit: Ogre::RbxMeshLoader  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00476640
//
// 00476640  56                   push esi
// 00476641  8bf1                 mov esi, ecx
// 00476643  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00476646  8b01                 mov eax, dword ptr [ecx]
// 00476648  8909                 mov dword ptr [ecx], ecx
// 0047664a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0047664d  894904               mov dword ptr [ecx + 4], ecx
// 00476650  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00476657  3b4614               cmp eax, dword ptr [esi + 0x14]
// 0047665a  7417                 je 0x476673
// 0047665c  57                   push edi
// 0047665d  8d4900               lea ecx, [ecx]
// 00476660  8b38                 mov edi, dword ptr [eax]
// 00476662  50                   push eax
// 00476663  e8ca232a00           call 0x718a32
// 00476668  83c404               add esp, 4
// 0047666b  8bc7                 mov eax, edi
// 0047666d  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 00476670  75ee                 jne 0x476660
// 00476672  5f                   pop edi
// 00476673  5e                   pop esi
// 00476674  c3                   ret 
// standard library list<ptr> (function ?clear@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
