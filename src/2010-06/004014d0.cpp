// from server: 100% by auto
// roc 2010-06 004014d0  unit: std::logic_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004014d0
//
// 004014d0  56                   push esi
// 004014d1  8bf1                 mov esi, ecx
// 004014d3  8d4e0c               lea ecx, [esi + 0xc]
// 004014d6  c7062c00a000         mov dword ptr [esi], 0xa0002c
// 004014dc  ff1500a49e00         call dword ptr [0x9ea400]
// 004014e2  8bce                 mov ecx, esi
// 004014e4  ff151ca99e00         call dword ptr [0x9ea91c]
// 004014ea  f644240801           test byte ptr [esp + 8], 1
// 004014ef  7409                 je 0x4014fa
// 004014f1  56                   push esi
// 004014f2  e8a3643a00           call 0x7a799a
// 004014f7  83c404               add esp, 4
// 004014fa  8bc6                 mov eax, esi
// 004014fc  5e                   pop esi
// 004014fd  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
