// from server: 100% by auto
// roc 2011-06 0040a9b0  unit: std::runtime_error  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040a9b0
//
// 0040a9b0  56                   push esi
// 0040a9b1  8bf1                 mov esi, ecx
// 0040a9b3  8d4e0c               lea ecx, [esi + 0xc]
// 0040a9b6  c70600bfa500         mov dword ptr [esi], 0xa5bf00
// 0040a9bc  ff15d004a400         call dword ptr [0xa404d0]
// 0040a9c2  8bce                 mov ecx, esi
// 0040a9c4  ff15640aa400         call dword ptr [0xa40a64]
// 0040a9ca  f644240801           test byte ptr [esp + 8], 1
// 0040a9cf  7409                 je 0x40a9da
// 0040a9d1  56                   push esi
// 0040a9d2  e881f63f00           call 0x80a058
// 0040a9d7  83c404               add esp, 4
// 0040a9da  8bc6                 mov eax, esi
// 0040a9dc  5e                   pop esi
// 0040a9dd  c20400               ret 4
// standard library vector<ptr> (function ??_Glogic_error@std@@UAEPAXI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
