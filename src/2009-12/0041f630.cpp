// from server: 100% by auto
// roc 2009-12 0041f630  unit: CSelectionTreeCtrl  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041f630
//
// 0041f630  83ec08               sub esp, 8
// 0041f633  53                   push ebx
// 0041f634  55                   push ebp
// 0041f635  56                   push esi
// 0041f636  8bf1                 mov esi, ecx
// 0041f638  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0041f63b  57                   push edi
// 0041f63c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0041f63f  7606                 jbe 0x41f647
// 0041f641  ff1560b79800         call dword ptr [0x98b760]
// 0041f647  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0041f64a  8b2e                 mov ebp, dword ptr [esi]
// 0041f64c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0041f64f  7606                 jbe 0x41f657
// 0041f651  ff1560b79800         call dword ptr [0x98b760]
// 0041f657  8b06                 mov eax, dword ptr [esi]
// 0041f659  53                   push ebx
// 0041f65a  55                   push ebp
// 0041f65b  57                   push edi
// 0041f65c  50                   push eax
// 0041f65d  8d442420             lea eax, [esp + 0x20]
// 0041f661  50                   push eax
// 0041f662  8bce                 mov ecx, esi
// 0041f664  e817552800           call 0x6a4b80
// 0041f669  5f                   pop edi
// 0041f66a  5e                   pop esi
// 0041f66b  5d                   pop ebp
// 0041f66c  5b                   pop ebx
// 0041f66d  83c408               add esp, 8
// 0041f670  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
