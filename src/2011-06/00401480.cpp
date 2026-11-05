// from server: 100% by auto
// roc 2011-06 00401480  unit: std::logic_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00401480
//
// 00401480  56                   push esi
// 00401481  8bf1                 mov esi, ecx
// 00401483  8d4e0c               lea ecx, [esi + 0xc]
// 00401486  c706c0b5a500         mov dword ptr [esi], 0xa5b5c0
// 0040148c  ff15d004a400         call dword ptr [0xa404d0]
// 00401492  8bce                 mov ecx, esi
// 00401494  ff15640aa400         call dword ptr [0xa40a64]
// 0040149a  f644240801           test byte ptr [esp + 8], 1
// 0040149f  7409                 je 0x4014aa
// 004014a1  56                   push esi
// 004014a2  e8b18b4000           call 0x80a058
// 004014a7  83c404               add esp, 4
// 004014aa  8bc6                 mov eax, esi
// 004014ac  5e                   pop esi
// 004014ad  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
