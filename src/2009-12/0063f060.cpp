// from server: 100% by auto
// roc 2009-12 0063f060  unit: std::runtime_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0063f060
//
// 0063f060  56                   push esi
// 0063f061  8bf1                 mov esi, ecx
// 0063f063  8d4e0c               lea ecx, [esi + 0xc]
// 0063f066  c706a0fd9900         mov dword ptr [esi], 0x99fda0
// 0063f06c  ff15e4b69800         call dword ptr [0x98b6e4]
// 0063f072  8bce                 mov ecx, esi
// 0063f074  ff1550b79800         call dword ptr [0x98b750]
// 0063f07a  f644240801           test byte ptr [esp + 8], 1
// 0063f07f  7409                 je 0x63f08a
// 0063f081  56                   push esi
// 0063f082  e8d3471b00           call 0x7f385a
// 0063f087  83c404               add esp, 4
// 0063f08a  8bc6                 mov eax, esi
// 0063f08c  5e                   pop esi
// 0063f08d  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
