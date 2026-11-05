// from server: 100% by auto
// roc 2009-06 005ea350  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ea350
//
// 005ea350  56                   push esi
// 005ea351  8bf1                 mov esi, ecx
// 005ea353  8b460c               mov eax, dword ptr [esi + 0xc]
// 005ea356  85c0                 test eax, eax
// 005ea358  7409                 je 0x5ea363
// 005ea35a  50                   push eax
// 005ea35b  e8d2e61200           call 0x718a32
// 005ea360  83c404               add esp, 4
// 005ea363  8b06                 mov eax, dword ptr [esi]
// 005ea365  50                   push eax
// 005ea366  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 005ea36d  c7461000000000       mov dword ptr [esi + 0x10], 0
// 005ea374  c7461400000000       mov dword ptr [esi + 0x14], 0
// 005ea37b  e8b2e61200           call 0x718a32
// 005ea380  83c404               add esp, 4
// 005ea383  5e                   pop esi
// 005ea384  c3                   ret 
// standard library vector<ptr> (function ??1?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
