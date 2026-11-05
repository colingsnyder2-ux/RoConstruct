// from server: 100% by auto
// roc 2012-06 0044d8a0  unit: std::logic_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044d8a0
//
// 0044d8a0  56                   push esi
// 0044d8a1  8bf1                 mov esi, ecx
// 0044d8a3  8d4e0c               lea ecx, [esi + 0xc]
// 0044d8a6  c706a02eb400         mov dword ptr [esi], 0xb42ea0
// 0044d8ac  ff153c26b200         call dword ptr [0xb2263c]
// 0044d8b2  8bce                 mov ecx, esi
// 0044d8b4  ff15d829b200         call dword ptr [0xb229d8]
// 0044d8ba  f644240801           test byte ptr [esp + 8], 1
// 0044d8bf  7409                 je 0x44d8ca
// 0044d8c1  56                   push esi
// 0044d8c2  e84d485300           call 0x982114
// 0044d8c7  83c404               add esp, 4
// 0044d8ca  8bc6                 mov eax, esi
// 0044d8cc  5e                   pop esi
// 0044d8cd  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
