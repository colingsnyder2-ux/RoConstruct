// from server: 100% by auto
// roc 2008-06 00428e50  unit: MainLogManager  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00428e50
//
// 00428e50  56                   push esi
// 00428e51  33c0                 xor eax, eax
// 00428e53  57                   push edi
// 00428e54  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00428e58  8bf1                 mov esi, ecx
// 00428e5a  89460c               mov dword ptr [esi + 0xc], eax
// 00428e5d  894610               mov dword ptr [esi + 0x10], eax
// 00428e60  894614               mov dword ptr [esi + 0x14], eax
// 00428e63  3bf8                 cmp edi, eax
// 00428e65  7507                 jne 0x428e6e
// 00428e67  5f                   pop edi
// 00428e68  32c0                 xor al, al
// 00428e6a  5e                   pop esi
// 00428e6b  c20400               ret 4
// 00428e6e  81ff49922409         cmp edi, 0x9249249
// 00428e74  7605                 jbe 0x428e7b
// 00428e76  e8c5de0900           call 0x4c6d40
// 00428e7b  50                   push eax
// 00428e7c  57                   push edi
// 00428e7d  e87e46ffff           call 0x41d500
// 00428e82  8d0cfd00000000       lea ecx, [edi*8]
// 00428e89  2bcf                 sub ecx, edi
// 00428e8b  83c408               add esp, 8
// 00428e8e  8d1488               lea edx, [eax + ecx*4]
// 00428e91  89460c               mov dword ptr [esi + 0xc], eax
// 00428e94  894610               mov dword ptr [esi + 0x10], eax
// 00428e97  5f                   pop edi
// 00428e98  895614               mov dword ptr [esi + 0x14], edx
// 00428e9b  b001                 mov al, 1
// 00428e9d  5e                   pop esi
// 00428e9e  c20400               ret 4
// standard library vector<string> (function ?_Buy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAE_NI@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
