// from server: 100% by auto
// roc 2008-06 00409dc0  unit: std::runtime_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00409dc0
//
// 00409dc0  56                   push esi
// 00409dc1  8bf1                 mov esi, ecx
// 00409dc3  8d4e0c               lea ecx, [esi + 0xc]
// 00409dc6  c706f8b78000         mov dword ptr [esi], 0x80b7f8
// 00409dcc  ff1568248000         call dword ptr [0x802468]
// 00409dd2  8bce                 mov ecx, esi
// 00409dd4  ff159c288000         call dword ptr [0x80289c]
// 00409dda  f644240801           test byte ptr [esp + 8], 1
// 00409ddf  7409                 je 0x409dea
// 00409de1  56                   push esi
// 00409de2  e893682900           call 0x6a067a
// 00409de7  83c404               add esp, 4
// 00409dea  8bc6                 mov eax, esi
// 00409dec  5e                   pop esi
// 00409ded  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
