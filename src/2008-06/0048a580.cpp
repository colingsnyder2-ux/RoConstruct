// from server: 100% by auto
// roc 2008-06 0048a580  unit: G3D::GWindow  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048a580
//
// 0048a580  64a100000000         mov eax, dword ptr fs:[0]
// 0048a586  6aff                 push -1
// 0048a588  6809e77c00           push 0x7ce709
// 0048a58d  50                   push eax
// 0048a58e  64892500000000       mov dword ptr fs:[0], esp
// 0048a595  83ec1c               sub esp, 0x1c
// 0048a598  56                   push esi
// 0048a599  8b742430             mov esi, dword ptr [esp + 0x30]
// 0048a59d  57                   push edi
// 0048a59e  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0048a5a2  3bf7                 cmp esi, edi
// 0048a5a4  7449                 je 0x48a5ef
// 0048a5a6  83ef1c               sub edi, 0x1c
// 0048a5a9  3bf7                 cmp esi, edi
// 0048a5ab  7442                 je 0x48a5ef
// 0048a5ad  56                   push esi
// 0048a5ae  8d4c240c             lea ecx, [esp + 0xc]
// 0048a5b2  ff155c248000         call dword ptr [0x80245c]
// 0048a5b8  57                   push edi
// 0048a5b9  8bce                 mov ecx, esi
// 0048a5bb  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0048a5c3  ff150c248000         call dword ptr [0x80240c]
// 0048a5c9  8d442408             lea eax, [esp + 8]
// 0048a5cd  50                   push eax
// 0048a5ce  8bcf                 mov ecx, edi
// 0048a5d0  ff150c248000         call dword ptr [0x80240c]
// 0048a5d6  8d4c2408             lea ecx, [esp + 8]
// 0048a5da  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0048a5e2  ff1568248000         call dword ptr [0x802468]
// 0048a5e8  83c61c               add esi, 0x1c
// 0048a5eb  3bf7                 cmp esi, edi
// 0048a5ed  75b7                 jne 0x48a5a6
// 0048a5ef  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0048a5f3  5f                   pop edi
// 0048a5f4  5e                   pop esi
// 0048a5f5  64890d00000000       mov dword ptr fs:[0], ecx
// 0048a5fc  83c428               add esp, 0x28
// 0048a5ff  c20800               ret 8
// standard library vector<string> (function ?_Reverse@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
