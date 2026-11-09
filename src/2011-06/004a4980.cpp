// from server: 100% by auto
// roc 2011-06 004a4980  unit: RBX::Network::Player  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004a4980
//
// 004a4980  64a100000000         mov eax, dword ptr fs:[0]
// 004a4986  6aff                 push -1
// 004a4988  68d9bc9d00           push 0x9dbcd9
// 004a498d  50                   push eax
// 004a498e  64892500000000       mov dword ptr fs:[0], esp
// 004a4995  83ec1c               sub esp, 0x1c
// 004a4998  56                   push esi
// 004a4999  8b742430             mov esi, dword ptr [esp + 0x30]
// 004a499d  57                   push edi
// 004a499e  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 004a49a2  3bf7                 cmp esi, edi
// 004a49a4  7449                 je 0x4a49ef
// 004a49a6  83ef1c               sub edi, 0x1c
// 004a49a9  3bf7                 cmp esi, edi
// 004a49ab  7442                 je 0x4a49ef
// 004a49ad  56                   push esi
// 004a49ae  8d4c240c             lea ecx, [esp + 0xc]
// 004a49b2  ff15c804a400         call dword ptr [0xa404c8]
// 004a49b8  57                   push edi
// 004a49b9  8bce                 mov ecx, esi
// 004a49bb  c744243000000000     mov dword ptr [esp + 0x30], 0
// 004a49c3  ff15a804a400         call dword ptr [0xa404a8]
// 004a49c9  8d442408             lea eax, [esp + 8]
// 004a49cd  50                   push eax
// 004a49ce  8bcf                 mov ecx, edi
// 004a49d0  ff15a804a400         call dword ptr [0xa404a8]
// 004a49d6  8d4c2408             lea ecx, [esp + 8]
// 004a49da  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 004a49e2  ff15d004a400         call dword ptr [0xa404d0]
// 004a49e8  83c61c               add esi, 0x1c
// 004a49eb  3bf7                 cmp esi, edi
// 004a49ed  75b7                 jne 0x4a49a6
// 004a49ef  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004a49f3  5f                   pop edi
// 004a49f4  5e                   pop esi
// 004a49f5  64890d00000000       mov dword ptr fs:[0], ecx
// 004a49fc  83c428               add esp, 0x28
// 004a49ff  c20800               ret 8
// standard library vector<string> (function ?_Reverse@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@0@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
