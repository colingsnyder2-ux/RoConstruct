// from server: 100% by auto
// roc 2009-12 00682b00  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00682b00
//
// 00682b00  53                   push ebx
// 00682b01  56                   push esi
// 00682b02  8bf1                 mov esi, ecx
// 00682b04  33db                 xor ebx, ebx
// 00682b06  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00682b09  741c                 je 0x682b27
// 00682b0b  eb03                 jmp 0x682b10
// 00682b0d  8d4900               lea ecx, [ecx]
// 00682b10  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00682b13  3bc3                 cmp eax, ebx
// 00682b15  740b                 je 0x682b22
// 00682b17  48                   dec eax
// 00682b18  89461c               mov dword ptr [esi + 0x1c], eax
// 00682b1b  3bc3                 cmp eax, ebx
// 00682b1d  7503                 jne 0x682b22
// 00682b1f  895e18               mov dword ptr [esi + 0x18], ebx
// 00682b22  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 00682b25  75e9                 jne 0x682b10
// 00682b27  57                   push edi
// 00682b28  8b7e14               mov edi, dword ptr [esi + 0x14]
// 00682b2b  3bfb                 cmp edi, ebx
// 00682b2d  761c                 jbe 0x682b4b
// 00682b2f  90                   nop 
// 00682b30  8b4610               mov eax, dword ptr [esi + 0x10]
// 00682b33  4f                   dec edi
// 00682b34  391cb8               cmp dword ptr [eax + edi*4], ebx
// 00682b37  8d04b8               lea eax, [eax + edi*4]
// 00682b3a  740b                 je 0x682b47
// 00682b3c  8b08                 mov ecx, dword ptr [eax]
// 00682b3e  51                   push ecx
// 00682b3f  e8160d1700           call 0x7f385a
// 00682b44  83c404               add esp, 4
// 00682b47  3bfb                 cmp edi, ebx
// 00682b49  77e5                 ja 0x682b30
// 00682b4b  8b4610               mov eax, dword ptr [esi + 0x10]
// 00682b4e  5f                   pop edi
// 00682b4f  3bc3                 cmp eax, ebx
// 00682b51  7409                 je 0x682b5c
// 00682b53  50                   push eax
// 00682b54  e8010d1700           call 0x7f385a
// 00682b59  83c404               add esp, 4
// 00682b5c  895e10               mov dword ptr [esi + 0x10], ebx
// 00682b5f  895e14               mov dword ptr [esi + 0x14], ebx
// 00682b62  5e                   pop esi
// 00682b63  5b                   pop ebx
// 00682b64  c3                   ret 
// standard library deque<ptr> (function ?_Tidy@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
