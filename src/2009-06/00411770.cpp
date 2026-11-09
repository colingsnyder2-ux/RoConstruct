// from server: 100% by auto
// roc 2009-06 00411770  unit: std::logic_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00411770
//
// 00411770  56                   push esi
// 00411771  8bf1                 mov esi, ecx
// 00411773  8d4e0c               lea ecx, [esi + 0xc]
// 00411776  c70644c98a00         mov dword ptr [esi], 0x8ac944
// 0041177c  ff15c4e48900         call dword ptr [0x89e4c4]
// 00411782  8bce                 mov ecx, esi
// 00411784  ff15bce98900         call dword ptr [0x89e9bc]
// 0041178a  f644240801           test byte ptr [esp + 8], 1
// 0041178f  7409                 je 0x41179a
// 00411791  56                   push esi
// 00411792  e89b723000           call 0x718a32
// 00411797  83c404               add esp, 4
// 0041179a  8bc6                 mov eax, esi
// 0041179c  5e                   pop esi
// 0041179d  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
