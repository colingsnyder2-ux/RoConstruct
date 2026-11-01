// from server: 100% by auto
// roc 2009-12 00424bd0  unit: ThreadLogManager  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00424bd0
//
// 00424bd0  56                   push esi
// 00424bd1  33c0                 xor eax, eax
// 00424bd3  57                   push edi
// 00424bd4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00424bd8  8bf1                 mov esi, ecx
// 00424bda  89460c               mov dword ptr [esi + 0xc], eax
// 00424bdd  894610               mov dword ptr [esi + 0x10], eax
// 00424be0  894614               mov dword ptr [esi + 0x14], eax
// 00424be3  3bf8                 cmp edi, eax
// 00424be5  7507                 jne 0x424bee
// 00424be7  5f                   pop edi
// 00424be8  32c0                 xor al, al
// 00424bea  5e                   pop esi
// 00424beb  c20400               ret 4
// 00424bee  81ff49922409         cmp edi, 0x9249249
// 00424bf4  7605                 jbe 0x424bfb
// 00424bf6  e865d50100           call 0x442160
// 00424bfb  50                   push eax
// 00424bfc  57                   push edi
// 00424bfd  e80e39ffff           call 0x418510
// 00424c02  8d0cfd00000000       lea ecx, [edi*8]
// 00424c09  2bcf                 sub ecx, edi
// 00424c0b  83c408               add esp, 8
// 00424c0e  8d1488               lea edx, [eax + ecx*4]
// 00424c11  89460c               mov dword ptr [esi + 0xc], eax
// 00424c14  894610               mov dword ptr [esi + 0x10], eax
// 00424c17  5f                   pop edi
// 00424c18  895614               mov dword ptr [esi + 0x14], edx
// 00424c1b  b001                 mov al, 1
// 00424c1d  5e                   pop esi
// 00424c1e  c20400               ret 4
// standard library vector<string> (function ?_Buy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAE_NI@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
