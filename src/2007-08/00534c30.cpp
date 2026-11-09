// from server: 100% by auto
// roc 2007-08 00534c30  unit: std::logic_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00534c30
//
// 00534c30  56                   push esi
// 00534c31  8bf1                 mov esi, ecx
// 00534c33  8d4e0c               lea ecx, [esi + 0xc]
// 00534c36  c706604e7800         mov dword ptr [esi], 0x784e60
// 00534c3c  ff15ace67700         call dword ptr [0x77e6ac]
// 00534c42  8bce                 mov ecx, esi
// 00534c44  ff15f4e67700         call dword ptr [0x77e6f4]
// 00534c4a  f644240801           test byte ptr [esp + 8], 1
// 00534c4f  7409                 je 0x534c5a
// 00534c51  56                   push esi
// 00534c52  e80bb00f00           call 0x62fc62
// 00534c57  83c404               add esp, 4
// 00534c5a  8bc6                 mov eax, esi
// 00534c5c  5e                   pop esi
// 00534c5d  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
