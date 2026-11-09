// from server: 100% by auto
// roc 2007-08 00412e30  unit: std::runtime_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00412e30
//
// 00412e30  56                   push esi
// 00412e31  8bf1                 mov esi, ecx
// 00412e33  8d4e0c               lea ecx, [esi + 0xc]
// 00412e36  c70618707800         mov dword ptr [esi], 0x787018
// 00412e3c  ff15ace67700         call dword ptr [0x77e6ac]
// 00412e42  8bce                 mov ecx, esi
// 00412e44  ff15f4e67700         call dword ptr [0x77e6f4]
// 00412e4a  f644240801           test byte ptr [esp + 8], 1
// 00412e4f  7409                 je 0x412e5a
// 00412e51  56                   push esi
// 00412e52  e80bce2100           call 0x62fc62
// 00412e57  83c404               add esp, 4
// 00412e5a  8bc6                 mov eax, esi
// 00412e5c  5e                   pop esi
// 00412e5d  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
