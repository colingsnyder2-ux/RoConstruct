// from server: 100% by auto
// roc 2008-06 0055c390  unit: std::logic_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c390
//
// 0055c390  56                   push esi
// 0055c391  8bf1                 mov esi, ecx
// 0055c393  8d4e0c               lea ecx, [esi + 0xc]
// 0055c396  c70610b18000         mov dword ptr [esi], 0x80b110
// 0055c39c  ff1568248000         call dword ptr [0x802468]
// 0055c3a2  8bce                 mov ecx, esi
// 0055c3a4  ff159c288000         call dword ptr [0x80289c]
// 0055c3aa  f644240801           test byte ptr [esp + 8], 1
// 0055c3af  7409                 je 0x55c3ba
// 0055c3b1  56                   push esi
// 0055c3b2  e8c3421400           call 0x6a067a
// 0055c3b7  83c404               add esp, 4
// 0055c3ba  8bc6                 mov eax, esi
// 0055c3bc  5e                   pop esi
// 0055c3bd  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
