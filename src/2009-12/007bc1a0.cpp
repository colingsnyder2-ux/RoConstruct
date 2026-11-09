// from server: 100% by auto
// roc 2009-12 007bc1a0  unit: RBX::SpatialFilter  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007bc1a0
//
// 007bc1a0  83ec08               sub esp, 8
// 007bc1a3  53                   push ebx
// 007bc1a4  55                   push ebp
// 007bc1a5  56                   push esi
// 007bc1a6  8bf1                 mov esi, ecx
// 007bc1a8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 007bc1ab  57                   push edi
// 007bc1ac  395e0c               cmp dword ptr [esi + 0xc], ebx
// 007bc1af  7606                 jbe 0x7bc1b7
// 007bc1b1  ff1560b79800         call dword ptr [0x98b760]
// 007bc1b7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007bc1ba  8b2e                 mov ebp, dword ptr [esi]
// 007bc1bc  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 007bc1bf  7606                 jbe 0x7bc1c7
// 007bc1c1  ff1560b79800         call dword ptr [0x98b760]
// 007bc1c7  8b06                 mov eax, dword ptr [esi]
// 007bc1c9  53                   push ebx
// 007bc1ca  55                   push ebp
// 007bc1cb  57                   push edi
// 007bc1cc  50                   push eax
// 007bc1cd  8d442420             lea eax, [esp + 0x20]
// 007bc1d1  50                   push eax
// 007bc1d2  8bce                 mov ecx, esi
// 007bc1d4  e807ffffff           call 0x7bc0e0
// 007bc1d9  5f                   pop edi
// 007bc1da  5e                   pop esi
// 007bc1db  5d                   pop ebp
// 007bc1dc  5b                   pop ebx
// 007bc1dd  83c408               add esp, 8
// 007bc1e0  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
