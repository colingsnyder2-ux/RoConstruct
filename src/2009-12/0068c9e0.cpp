// from server: 100% by auto
// roc 2009-12 0068c9e0  unit: RBX::RootInstance  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068c9e0
//
// 0068c9e0  56                   push esi
// 0068c9e1  33c0                 xor eax, eax
// 0068c9e3  57                   push edi
// 0068c9e4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0068c9e8  8bf1                 mov esi, ecx
// 0068c9ea  89460c               mov dword ptr [esi + 0xc], eax
// 0068c9ed  894610               mov dword ptr [esi + 0x10], eax
// 0068c9f0  894614               mov dword ptr [esi + 0x14], eax
// 0068c9f3  3bf8                 cmp edi, eax
// 0068c9f5  7507                 jne 0x68c9fe
// 0068c9f7  5f                   pop edi
// 0068c9f8  32c0                 xor al, al
// 0068c9fa  5e                   pop esi
// 0068c9fb  c20400               ret 4
// 0068c9fe  81ffffffff1f         cmp edi, 0x1fffffff
// 0068ca04  7605                 jbe 0x68ca0b
// 0068ca06  e85557dbff           call 0x442160
// 0068ca0b  50                   push eax
// 0068ca0c  57                   push edi
// 0068ca0d  e8bef0eeff           call 0x57bad0
// 0068ca12  89460c               mov dword ptr [esi + 0xc], eax
// 0068ca15  894610               mov dword ptr [esi + 0x10], eax
// 0068ca18  83c408               add esp, 8
// 0068ca1b  8d04f8               lea eax, [eax + edi*8]
// 0068ca1e  894614               mov dword ptr [esi + 0x14], eax
// 0068ca21  5f                   pop edi
// 0068ca22  b001                 mov al, 1
// 0068ca24  5e                   pop esi
// 0068ca25  c20400               ret 4
// standard library vector<double> (function ?_Buy@?$vector@NV?$allocator@N@std@@@std@@IAE_NI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
