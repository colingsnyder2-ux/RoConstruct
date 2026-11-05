// from server: 100% by auto
// roc 2012-06 00574720  unit: AsyncResult  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00574720
//
// 00574720  53                   push ebx
// 00574721  56                   push esi
// 00574722  8bf1                 mov esi, ecx
// 00574724  33db                 xor ebx, ebx
// 00574726  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00574729  741c                 je 0x574747
// 0057472b  eb03                 jmp 0x574730
// 0057472d  8d4900               lea ecx, [ecx]
// 00574730  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00574733  3bc3                 cmp eax, ebx
// 00574735  740b                 je 0x574742
// 00574737  48                   dec eax
// 00574738  89461c               mov dword ptr [esi + 0x1c], eax
// 0057473b  3bc3                 cmp eax, ebx
// 0057473d  7503                 jne 0x574742
// 0057473f  895e18               mov dword ptr [esi + 0x18], ebx
// 00574742  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00574745  75e9                 jne 0x574730
// 00574747  57                   push edi
// 00574748  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0057474b  3bfb                 cmp edi, ebx
// 0057474d  761c                 jbe 0x57476b
// 0057474f  90                   nop 
// 00574750  8b4610               mov eax, dword ptr [esi + 0x10]
// 00574753  4f                   dec edi
// 00574754  391cb8               cmp dword ptr [eax + edi*4], ebx
// 00574757  8d04b8               lea eax, [eax + edi*4]
// 0057475a  740b                 je 0x574767
// 0057475c  8b08                 mov ecx, dword ptr [eax]
// 0057475e  51                   push ecx
// 0057475f  e8b0d94000           call 0x982114
// 00574764  83c404               add esp, 4
// 00574767  3bfb                 cmp edi, ebx
// 00574769  77e5                 ja 0x574750
// 0057476b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0057476e  5f                   pop edi
// 0057476f  3bc3                 cmp eax, ebx
// 00574771  7409                 je 0x57477c
// 00574773  50                   push eax
// 00574774  e89bd94000           call 0x982114
// 00574779  83c404               add esp, 4
// 0057477c  895e10               mov dword ptr [esi + 0x10], ebx
// 0057477f  895e14               mov dword ptr [esi + 0x14], ebx
// 00574782  5e                   pop esi
// 00574783  5b                   pop ebx
// 00574784  c3                   ret 
// standard library deque<ptr> (function ?_Tidy@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
