// from server: 100% by auto
// roc 2007-08 0040fb40  unit: CopyVerb  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040fb40
//
// 0040fb40  53                   push ebx
// 0040fb41  56                   push esi
// 0040fb42  8bf1                 mov esi, ecx
// 0040fb44  33db                 xor ebx, ebx
// 0040fb46  395e10               cmp dword ptr [esi + 0x10], ebx
// 0040fb49  741e                 je 0x40fb69
// 0040fb4b  eb03                 jmp 0x40fb50
// 0040fb4d  8d4900               lea ecx, [ecx]
// 0040fb50  8b4610               mov eax, dword ptr [esi + 0x10]
// 0040fb53  3bc3                 cmp eax, ebx
// 0040fb55  740d                 je 0x40fb64
// 0040fb57  83c0ff               add eax, -1
// 0040fb5a  3bc3                 cmp eax, ebx
// 0040fb5c  894610               mov dword ptr [esi + 0x10], eax
// 0040fb5f  7503                 jne 0x40fb64
// 0040fb61  895e0c               mov dword ptr [esi + 0xc], ebx
// 0040fb64  395e10               cmp dword ptr [esi + 0x10], ebx
// 0040fb67  75e7                 jne 0x40fb50
// 0040fb69  57                   push edi
// 0040fb6a  8b7e08               mov edi, dword ptr [esi + 8]
// 0040fb6d  3bfb                 cmp edi, ebx
// 0040fb6f  761d                 jbe 0x40fb8e
// 0040fb71  8b4604               mov eax, dword ptr [esi + 4]
// 0040fb74  83ef01               sub edi, 1
// 0040fb77  391cb8               cmp dword ptr [eax + edi*4], ebx
// 0040fb7a  8d04b8               lea eax, [eax + edi*4]
// 0040fb7d  740b                 je 0x40fb8a
// 0040fb7f  8b08                 mov ecx, dword ptr [eax]
// 0040fb81  51                   push ecx
// 0040fb82  e8db002200           call 0x62fc62
// 0040fb87  83c404               add esp, 4
// 0040fb8a  3bfb                 cmp edi, ebx
// 0040fb8c  77e3                 ja 0x40fb71
// 0040fb8e  8b4604               mov eax, dword ptr [esi + 4]
// 0040fb91  3bc3                 cmp eax, ebx
// 0040fb93  5f                   pop edi
// 0040fb94  7409                 je 0x40fb9f
// 0040fb96  50                   push eax
// 0040fb97  e8c6002200           call 0x62fc62
// 0040fb9c  83c404               add esp, 4
// 0040fb9f  895e04               mov dword ptr [esi + 4], ebx
// 0040fba2  895e08               mov dword ptr [esi + 8], ebx
// 0040fba5  5e                   pop esi
// 0040fba6  5b                   pop ebx
// 0040fba7  c3                   ret 
// standard library deque<ptr> (function ?_Tidy@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXXZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
