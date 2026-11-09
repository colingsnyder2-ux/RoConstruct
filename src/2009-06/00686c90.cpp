// from server: 100% by auto
// roc 2009-06 00686c90  unit: std::runtime_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00686c90
//
// 00686c90  56                   push esi
// 00686c91  8bf1                 mov esi, ecx
// 00686c93  8d4e0c               lea ecx, [esi + 0xc]
// 00686c96  c7065cd28a00         mov dword ptr [esi], 0x8ad25c
// 00686c9c  ff15c4e48900         call dword ptr [0x89e4c4]
// 00686ca2  8bce                 mov ecx, esi
// 00686ca4  ff15bce98900         call dword ptr [0x89e9bc]
// 00686caa  f644240801           test byte ptr [esp + 8], 1
// 00686caf  7409                 je 0x686cba
// 00686cb1  56                   push esi
// 00686cb2  e87b1d0900           call 0x718a32
// 00686cb7  83c404               add esp, 4
// 00686cba  8bc6                 mov eax, esi
// 00686cbc  5e                   pop esi
// 00686cbd  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
