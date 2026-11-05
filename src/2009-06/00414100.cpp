// from server: 100% by auto
// roc 2009-06 00414100  unit: CopyVerb  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00414100
//
// 00414100  56                   push esi
// 00414101  33c0                 xor eax, eax
// 00414103  57                   push edi
// 00414104  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00414108  8bf1                 mov esi, ecx
// 0041410a  89460c               mov dword ptr [esi + 0xc], eax
// 0041410d  894610               mov dword ptr [esi + 0x10], eax
// 00414110  894614               mov dword ptr [esi + 0x14], eax
// 00414113  3bf8                 cmp edi, eax
// 00414115  7507                 jne 0x41411e
// 00414117  5f                   pop edi
// 00414118  32c0                 xor al, al
// 0041411a  5e                   pop esi
// 0041411b  c20400               ret 4
// 0041411e  81ffffffff1f         cmp edi, 0x1fffffff
// 00414124  7605                 jbe 0x41412b
// 00414126  e835c20700           call 0x490360
// 0041412b  50                   push eax
// 0041412c  57                   push edi
// 0041412d  e8be0d0700           call 0x484ef0
// 00414132  89460c               mov dword ptr [esi + 0xc], eax
// 00414135  894610               mov dword ptr [esi + 0x10], eax
// 00414138  83c408               add esp, 8
// 0041413b  8d04f8               lea eax, [eax + edi*8]
// 0041413e  894614               mov dword ptr [esi + 0x14], eax
// 00414141  5f                   pop edi
// 00414142  b001                 mov al, 1
// 00414144  5e                   pop esi
// 00414145  c20400               ret 4
// standard library vector<double> (function ?_Buy@?$vector@NV?$allocator@N@std@@@std@@IAE_NI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
