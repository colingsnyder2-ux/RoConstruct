// from server: 100% by auto
// roc 2008-06 0064fa10  unit: RBX::ImageKeyButton  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064fa10
//
// 0064fa10  53                   push ebx
// 0064fa11  56                   push esi
// 0064fa12  8bf1                 mov esi, ecx
// 0064fa14  33db                 xor ebx, ebx
// 0064fa16  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0064fa19  741c                 je 0x64fa37
// 0064fa1b  eb03                 jmp 0x64fa20
// 0064fa1d  8d4900               lea ecx, [ecx]
// 0064fa20  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0064fa23  3bc3                 cmp eax, ebx
// 0064fa25  740b                 je 0x64fa32
// 0064fa27  48                   dec eax
// 0064fa28  89461c               mov dword ptr [esi + 0x1c], eax
// 0064fa2b  3bc3                 cmp eax, ebx
// 0064fa2d  7503                 jne 0x64fa32
// 0064fa2f  895e18               mov dword ptr [esi + 0x18], ebx
// 0064fa32  395e1c               cmp dword ptr [esi + 0x1c], ebx
// 0064fa35  75e9                 jne 0x64fa20
// 0064fa37  57                   push edi
// 0064fa38  8b7e14               mov edi, dword ptr [esi + 0x14]
// 0064fa3b  3bfb                 cmp edi, ebx
// 0064fa3d  761c                 jbe 0x64fa5b
// 0064fa3f  90                   nop 
// 0064fa40  8b4610               mov eax, dword ptr [esi + 0x10]
// 0064fa43  4f                   dec edi
// 0064fa44  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0064fa47  8d04b8               lea eax, [eax + edi*4]
// 0064fa4a  740b                 je 0x64fa57
// 0064fa4c  8b08                 mov ecx, dword ptr [eax]
// 0064fa4e  51                   push ecx
// 0064fa4f  e8260c0500           call 0x6a067a
// 0064fa54  83c404               add esp, 4
// 0064fa57  3bfb                 cmp edi, ebx
// 0064fa59  77e5                 ja 0x64fa40
// 0064fa5b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0064fa5e  5f                   pop edi
// 0064fa5f  3bc3                 cmp eax, ebx
// 0064fa61  7409                 je 0x64fa6c
// 0064fa63  50                   push eax
// 0064fa64  e8110c0500           call 0x6a067a
// 0064fa69  83c404               add esp, 4
// 0064fa6c  895e10               mov dword ptr [esi + 0x10], ebx
// 0064fa6f  895e14               mov dword ptr [esi + 0x14], ebx
// 0064fa72  5e                   pop esi
// 0064fa73  5b                   pop ebx
// 0064fa74  c3                   ret 
// standard library deque<ptr> (function ?_Tidy@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
