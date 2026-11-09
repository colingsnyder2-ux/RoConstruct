// from server: 100% by auto
// roc 2010-06 005a0ef0  unit: std::runtime_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005a0ef0
//
// 005a0ef0  56                   push esi
// 005a0ef1  8bf1                 mov esi, ecx
// 005a0ef3  8d4e0c               lea ecx, [esi + 0xc]
// 005a0ef6  c7063009a000         mov dword ptr [esi], 0xa00930
// 005a0efc  ff1500a49e00         call dword ptr [0x9ea400]
// 005a0f02  8bce                 mov ecx, esi
// 005a0f04  ff151ca99e00         call dword ptr [0x9ea91c]
// 005a0f0a  f644240801           test byte ptr [esp + 8], 1
// 005a0f0f  7409                 je 0x5a0f1a
// 005a0f11  56                   push esi
// 005a0f12  e8836a2000           call 0x7a799a
// 005a0f17  83c404               add esp, 4
// 005a0f1a  8bc6                 mov eax, esi
// 005a0f1c  5e                   pop esi
// 005a0f1d  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
