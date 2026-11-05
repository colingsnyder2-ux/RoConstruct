// from server: 100% by auto
// roc 2009-12 00722c00  unit: UString_sink::?$stream_buffer  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00722c00
//
// 00722c00  56                   push esi
// 00722c01  8bf1                 mov esi, ecx
// 00722c03  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00722c06  8b01                 mov eax, dword ptr [ecx]
// 00722c08  8909                 mov dword ptr [ecx], ecx
// 00722c0a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00722c0d  894904               mov dword ptr [ecx + 4], ecx
// 00722c10  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00722c17  3b4614               cmp eax, dword ptr [esi + 0x14]
// 00722c1a  7417                 je 0x722c33
// 00722c1c  57                   push edi
// 00722c1d  8d4900               lea ecx, [ecx]
// 00722c20  8b38                 mov edi, dword ptr [eax]
// 00722c22  50                   push eax
// 00722c23  e8320c0d00           call 0x7f385a
// 00722c28  83c404               add esp, 4
// 00722c2b  8bc7                 mov eax, edi
// 00722c2d  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 00722c30  75ee                 jne 0x722c20
// 00722c32  5f                   pop edi
// 00722c33  8b4614               mov eax, dword ptr [esi + 0x14]
// 00722c36  50                   push eax
// 00722c37  e81e0c0d00           call 0x7f385a
// 00722c3c  83c404               add esp, 4
// 00722c3f  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00722c46  5e                   pop esi
// 00722c47  c3                   ret 
// standard library list<ptr> (function ?_Tidy@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
