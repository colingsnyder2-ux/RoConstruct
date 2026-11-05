// from server: 100% by auto
// roc 2012-06 00859010  unit: std::runtime_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00859010
//
// 00859010  56                   push esi
// 00859011  8bf1                 mov esi, ecx
// 00859013  8d4e0c               lea ecx, [esi + 0xc]
// 00859016  c7064c3cb400         mov dword ptr [esi], 0xb43c4c
// 0085901c  ff153c26b200         call dword ptr [0xb2263c]
// 00859022  8bce                 mov ecx, esi
// 00859024  ff15d829b200         call dword ptr [0xb229d8]
// 0085902a  f644240801           test byte ptr [esp + 8], 1
// 0085902f  7409                 je 0x85903a
// 00859031  56                   push esi
// 00859032  e8dd901200           call 0x982114
// 00859037  83c404               add esp, 4
// 0085903a  8bc6                 mov eax, esi
// 0085903c  5e                   pop esi
// 0085903d  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
