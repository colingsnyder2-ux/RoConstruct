// from server: 100% by auto
// roc 2009-06 00414150  unit: CopyVerb  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00414150
//
// 00414150  53                   push ebx
// 00414151  56                   push esi
// 00414152  8bf1                 mov esi, ecx
// 00414154  33db                 xor ebx, ebx
// 00414156  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00414159  741c                 je 0x414177
// 0041415b  eb03                 jmp 0x414160
// 0041415d  8d4900               lea ecx, [ecx]
// 00414160  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00414163  3bc3                 cmp eax, ebx
// 00414165  740b                 je 0x414172
// 00414167  48                   dec eax
// 00414168  89461c               mov dword ptr [esi + 0x1c], eax
// 0041416b  3bc3                 cmp eax, ebx
// 0041416d  7503                 jne 0x414172
// 0041416f  895e18               mov dword ptr [esi + 0x18], ebx
// 00414172  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00414175  75e9                 jne 0x414160
// 00414177  57                   push edi
// 00414178  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0041417b  3bfb                 cmp edi, ebx
// 0041417d  761c                 jbe 0x41419b
// 0041417f  90                   nop 
// 00414180  8b4610               mov eax, dword ptr [esi + 0x10]
// 00414183  4f                   dec edi
// 00414184  391cb8               cmp dword ptr [eax + edi*4], ebx
// 00414187  8d04b8               lea eax, [eax + edi*4]
// 0041418a  740b                 je 0x414197
// 0041418c  8b08                 mov ecx, dword ptr [eax]
// 0041418e  51                   push ecx
// 0041418f  e89e483000           call 0x718a32
// 00414194  83c404               add esp, 4
// 00414197  3bfb                 cmp edi, ebx
// 00414199  77e5                 ja 0x414180
// 0041419b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0041419e  5f                   pop edi
// 0041419f  3bc3                 cmp eax, ebx
// 004141a1  7409                 je 0x4141ac
// 004141a3  50                   push eax
// 004141a4  e889483000           call 0x718a32
// 004141a9  83c404               add esp, 4
// 004141ac  895e10               mov dword ptr [esi + 0x10], ebx
// 004141af  895e14               mov dword ptr [esi + 0x14], ebx
// 004141b2  5e                   pop esi
// 004141b3  5b                   pop ebx
// 004141b4  c3                   ret 
// standard library deque<ptr> (function ?_Tidy@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
