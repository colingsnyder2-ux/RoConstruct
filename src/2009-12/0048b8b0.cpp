// from server: 100% by auto
// roc 2009-12 0048b8b0  unit: std::logic_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048b8b0
//
// 0048b8b0  56                   push esi
// 0048b8b1  8bf1                 mov esi, ecx
// 0048b8b3  8d4e0c               lea ecx, [esi + 0xc]
// 0048b8b6  c70684f49900         mov dword ptr [esi], 0x99f484
// 0048b8bc  ff15e4b69800         call dword ptr [0x98b6e4]
// 0048b8c2  8bce                 mov ecx, esi
// 0048b8c4  ff1550b79800         call dword ptr [0x98b750]
// 0048b8ca  f644240801           test byte ptr [esp + 8], 1
// 0048b8cf  7409                 je 0x48b8da
// 0048b8d1  56                   push esi
// 0048b8d2  e8837f3600           call 0x7f385a
// 0048b8d7  83c404               add esp, 4
// 0048b8da  8bc6                 mov eax, esi
// 0048b8dc  5e                   pop esi
// 0048b8dd  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
