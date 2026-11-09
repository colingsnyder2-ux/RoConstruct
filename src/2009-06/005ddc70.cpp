// from server: 100% by auto
// roc 2009-06 005ddc70  unit: RBX::VInstance::?$NonFactoryProduct  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ddc70
//
// 005ddc70  55                   push ebp
// 005ddc71  8bec                 mov ebp, esp
// 005ddc73  6aff                 push -1
// 005ddc75  6828388600           push 0x863828
// 005ddc7a  64a100000000         mov eax, dword ptr fs:[0]
// 005ddc80  50                   push eax
// 005ddc81  64892500000000       mov dword ptr fs:[0], esp
// 005ddc88  83ec0c               sub esp, 0xc
// 005ddc8b  53                   push ebx
// 005ddc8c  56                   push esi
// 005ddc8d  57                   push edi
// 005ddc8e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005ddc91  8bf9                 mov edi, ecx
// 005ddc93  6a04                 push 4
// 005ddc95  897de8               mov dword ptr [ebp - 0x18], edi
// 005ddc98  e89bad1300           call 0x718a38
// 005ddc9d  33c9                 xor ecx, ecx
// 005ddc9f  83c404               add esp, 4
// 005ddca2  3bc1                 cmp eax, ecx
// 005ddca4  7404                 je 0x5ddcaa
// 005ddca6  8938                 mov dword ptr [eax], edi
// 005ddca8  eb02                 jmp 0x5ddcac
// 005ddcaa  33c0                 xor eax, eax
// 005ddcac  8907                 mov dword ptr [edi], eax
// 005ddcae  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005ddcb1  8b7310               mov esi, dword ptr [ebx + 0x10]
// 005ddcb4  2b730c               sub esi, dword ptr [ebx + 0xc]
// 005ddcb7  894dfc               mov dword ptr [ebp - 4], ecx
// 005ddcba  c1fe05               sar esi, 5
// 005ddcbd  894f0c               mov dword ptr [edi + 0xc], ecx
// 005ddcc0  894f10               mov dword ptr [edi + 0x10], ecx
// 005ddcc3  894f14               mov dword ptr [edi + 0x14], ecx
// 005ddcc6  3bf1                 cmp esi, ecx
// 005ddcc8  746c                 je 0x5ddd36
// 005ddcca  81feffffff07         cmp esi, 0x7ffffff
// 005ddcd0  7605                 jbe 0x5ddcd7
// 005ddcd2  e88926ebff           call 0x490360
// 005ddcd7  51                   push ecx
// 005ddcd8  56                   push esi
// 005ddcd9  e8d2b5ffff           call 0x5d92b0
// 005ddcde  c1e605               shl esi, 5
// 005ddce1  03f0                 add esi, eax
// 005ddce3  89470c               mov dword ptr [edi + 0xc], eax
// 005ddce6  894710               mov dword ptr [edi + 0x10], eax
// 005ddce9  897714               mov dword ptr [edi + 0x14], esi
// 005ddcec  8b4310               mov eax, dword ptr [ebx + 0x10]
// 005ddcef  83c408               add esp, 8
// 005ddcf2  c645fc01             mov byte ptr [ebp - 4], 1
// 005ddcf6  8945ec               mov dword ptr [ebp - 0x14], eax
// 005ddcf9  39430c               cmp dword ptr [ebx + 0xc], eax
// 005ddcfc  7606                 jbe 0x5ddd04
// 005ddcfe  ff15ace98900         call dword ptr [0x89e9ac]
// 005ddd04  8b730c               mov esi, dword ptr [ebx + 0xc]
// 005ddd07  3b7310               cmp esi, dword ptr [ebx + 0x10]
// 005ddd0a  7606                 jbe 0x5ddd12
// 005ddd0c  ff15ace98900         call dword ptr [0x89e9ac]
// 005ddd12  8b470c               mov eax, dword ptr [edi + 0xc]
// 005ddd15  c6450800             mov byte ptr [ebp + 8], 0
// 005ddd19  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005ddd1c  8b5508               mov edx, dword ptr [ebp + 8]
// 005ddd1f  51                   push ecx
// 005ddd20  52                   push edx
// 005ddd21  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 005ddd24  8d4f08               lea ecx, [edi + 8]
// 005ddd27  51                   push ecx
// 005ddd28  50                   push eax
// 005ddd29  52                   push edx
// 005ddd2a  56                   push esi
// 005ddd2b  e860e0ffff           call 0x5dbd90
// 005ddd30  83c418               add esp, 0x18
// 005ddd33  894710               mov dword ptr [edi + 0x10], eax
// 005ddd36  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005ddd39  8bc7                 mov eax, edi
// 005ddd3b  5f                   pop edi
// 005ddd3c  5e                   pop esi
// 005ddd3d  64890d00000000       mov dword ptr fs:[0], ecx
// 005ddd44  5b                   pop ebx
// 005ddd45  8be5                 mov esp, ebp
// 005ddd47  5d                   pop ebp
// 005ddd48  c20400               ret 4
// standard library vector<pod32> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
