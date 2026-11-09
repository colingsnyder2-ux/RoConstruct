// from server: 100% by auto
// roc 2010-06 00740b60  unit: RBX::VHttp::?$sp_counted_impl_p  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00740b60
//
// 00740b60  56                   push esi
// 00740b61  8bf1                 mov esi, ecx
// 00740b63  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00740b66  8b01                 mov eax, dword ptr [ecx]
// 00740b68  8909                 mov dword ptr [ecx], ecx
// 00740b6a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00740b6d  894904               mov dword ptr [ecx + 4], ecx
// 00740b70  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00740b77  3b4614               cmp eax, dword ptr [esi + 0x14]
// 00740b7a  7417                 je 0x740b93
// 00740b7c  57                   push edi
// 00740b7d  8d4900               lea ecx, [ecx]
// 00740b80  8b38                 mov edi, dword ptr [eax]
// 00740b82  50                   push eax
// 00740b83  e8126e0600           call 0x7a799a
// 00740b88  83c404               add esp, 4
// 00740b8b  8bc7                 mov eax, edi
// 00740b8d  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 00740b90  75ee                 jne 0x740b80
// 00740b92  5f                   pop edi
// 00740b93  8b4614               mov eax, dword ptr [esi + 0x14]
// 00740b96  50                   push eax
// 00740b97  e8fe6d0600           call 0x7a799a
// 00740b9c  83c404               add esp, 4
// 00740b9f  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00740ba6  5e                   pop esi
// 00740ba7  c3                   ret 
// standard library list<ptr> (function ?_Tidy@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
