// from server: 100% by auto
// roc 2009-06 004242d0  unit: MainLogManager  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004242d0
//
// 004242d0  56                   push esi
// 004242d1  33c0                 xor eax, eax
// 004242d3  57                   push edi
// 004242d4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004242d8  8bf1                 mov esi, ecx
// 004242da  89460c               mov dword ptr [esi + 0xc], eax
// 004242dd  894610               mov dword ptr [esi + 0x10], eax
// 004242e0  894614               mov dword ptr [esi + 0x14], eax
// 004242e3  3bf8                 cmp edi, eax
// 004242e5  7507                 jne 0x4242ee
// 004242e7  5f                   pop edi
// 004242e8  32c0                 xor al, al
// 004242ea  5e                   pop esi
// 004242eb  c20400               ret 4
// 004242ee  81ff49922409         cmp edi, 0x9249249
// 004242f4  7605                 jbe 0x4242fb
// 004242f6  e865c00600           call 0x490360
// 004242fb  50                   push eax
// 004242fc  57                   push edi
// 004242fd  e8de3dffff           call 0x4180e0
// 00424302  8d0cfd00000000       lea ecx, [edi*8]
// 00424309  2bcf                 sub ecx, edi
// 0042430b  83c408               add esp, 8
// 0042430e  8d1488               lea edx, [eax + ecx*4]
// 00424311  89460c               mov dword ptr [esi + 0xc], eax
// 00424314  894610               mov dword ptr [esi + 0x10], eax
// 00424317  5f                   pop edi
// 00424318  895614               mov dword ptr [esi + 0x14], edx
// 0042431b  b001                 mov al, 1
// 0042431d  5e                   pop esi
// 0042431e  c20400               ret 4
// standard library vector<string> (function ?_Buy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAE_NI@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
