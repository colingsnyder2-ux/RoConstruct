// from server: 100% by auto
// roc 2009-06 00622390  unit: RBX::RootInstance  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00622390
//
// 00622390  56                   push esi
// 00622391  8bf1                 mov esi, ecx
// 00622393  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00622396  8b01                 mov eax, dword ptr [ecx]
// 00622398  8909                 mov dword ptr [ecx], ecx
// 0062239a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 0062239d  894904               mov dword ptr [ecx + 4], ecx
// 006223a0  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006223a7  3b4614               cmp eax, dword ptr [esi + 0x14]
// 006223aa  7417                 je 0x6223c3
// 006223ac  57                   push edi
// 006223ad  8d4900               lea ecx, [ecx]
// 006223b0  8b38                 mov edi, dword ptr [eax]
// 006223b2  50                   push eax
// 006223b3  e87a660f00           call 0x718a32
// 006223b8  83c404               add esp, 4
// 006223bb  8bc7                 mov eax, edi
// 006223bd  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 006223c0  75ee                 jne 0x6223b0
// 006223c2  5f                   pop edi
// 006223c3  8b4614               mov eax, dword ptr [esi + 0x14]
// 006223c6  50                   push eax
// 006223c7  e866660f00           call 0x718a32
// 006223cc  83c404               add esp, 4
// 006223cf  c7461400000000       mov dword ptr [esi + 0x14], 0
// 006223d6  5e                   pop esi
// 006223d7  c3                   ret 
// standard library list<ptr> (function ?_Tidy@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
