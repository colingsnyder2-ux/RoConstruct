// from server: 100% by auto
// roc 2007-08 00428ed0  unit: MainLogManager  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00428ed0
//
// 00428ed0  56                   push esi
// 00428ed1  33c0                 xor eax, eax
// 00428ed3  57                   push edi
// 00428ed4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00428ed8  3bf8                 cmp edi, eax
// 00428eda  8bf1                 mov esi, ecx
// 00428edc  894604               mov dword ptr [esi + 4], eax
// 00428edf  894608               mov dword ptr [esi + 8], eax
// 00428ee2  89460c               mov dword ptr [esi + 0xc], eax
// 00428ee5  7507                 jne 0x428eee
// 00428ee7  5f                   pop edi
// 00428ee8  32c0                 xor al, al
// 00428eea  5e                   pop esi
// 00428eeb  c20400               ret 4
// 00428eee  81ff49922409         cmp edi, 0x9249249
// 00428ef4  7605                 jbe 0x428efb
// 00428ef6  e805e9feff           call 0x417800
// 00428efb  50                   push eax
// 00428efc  57                   push edi
// 00428efd  e85e27ffff           call 0x41b660
// 00428f02  8d0cfd00000000       lea ecx, [edi*8]
// 00428f09  2bcf                 sub ecx, edi
// 00428f0b  83c408               add esp, 8
// 00428f0e  8d1488               lea edx, [eax + ecx*4]
// 00428f11  894604               mov dword ptr [esi + 4], eax
// 00428f14  894608               mov dword ptr [esi + 8], eax
// 00428f17  5f                   pop edi
// 00428f18  89560c               mov dword ptr [esi + 0xc], edx
// 00428f1b  b001                 mov al, 1
// 00428f1d  5e                   pop esi
// 00428f1e  c20400               ret 4
// standard library vector<string> (function ?_Buy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAE_NI@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
