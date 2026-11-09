// from server: 100% by auto
// roc 2010-06 00413dc0  unit: CopyVerb  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413dc0
//
// 00413dc0  53                   push ebx
// 00413dc1  56                   push esi
// 00413dc2  8bf1                 mov esi, ecx
// 00413dc4  33db                 xor ebx, ebx
// 00413dc6  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00413dc9  741c                 je 0x413de7
// 00413dcb  eb03                 jmp 0x413dd0
// 00413dcd  8d4900               lea ecx, [ecx]
// 00413dd0  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00413dd3  3bc3                 cmp eax, ebx
// 00413dd5  740b                 je 0x413de2
// 00413dd7  48                   dec eax
// 00413dd8  89461c               mov dword ptr [esi + 0x1c], eax
// 00413ddb  3bc3                 cmp eax, ebx
// 00413ddd  7503                 jne 0x413de2
// 00413ddf  895e18               mov dword ptr [esi + 0x18], ebx
// 00413de2  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00413de5  75e9                 jne 0x413dd0
// 00413de7  57                   push edi
// 00413de8  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00413deb  3bfb                 cmp edi, ebx
// 00413ded  761c                 jbe 0x413e0b
// 00413def  90                   nop 
// 00413df0  8b4610               mov eax, dword ptr [esi + 0x10]
// 00413df3  4f                   dec edi
// 00413df4  391cb8               cmp dword ptr [eax + edi*4], ebx
// 00413df7  8d04b8               lea eax, [eax + edi*4]
// 00413dfa  740b                 je 0x413e07
// 00413dfc  8b08                 mov ecx, dword ptr [eax]
// 00413dfe  51                   push ecx
// 00413dff  e8963b3900           call 0x7a799a
// 00413e04  83c404               add esp, 4
// 00413e07  3bfb                 cmp edi, ebx
// 00413e09  77e5                 ja 0x413df0
// 00413e0b  8b4610               mov eax, dword ptr [esi + 0x10]
// 00413e0e  5f                   pop edi
// 00413e0f  3bc3                 cmp eax, ebx
// 00413e11  7409                 je 0x413e1c
// 00413e13  50                   push eax
// 00413e14  e8813b3900           call 0x7a799a
// 00413e19  83c404               add esp, 4
// 00413e1c  895e10               mov dword ptr [esi + 0x10], ebx
// 00413e1f  895e14               mov dword ptr [esi + 0x14], ebx
// 00413e22  5e                   pop esi
// 00413e23  5b                   pop ebx
// 00413e24  c3                   ret 
// standard library deque<ptr> (function ?_Tidy@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
