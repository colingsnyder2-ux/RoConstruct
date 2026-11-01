// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00560a70  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00560a70
//
// 00560a70  55                   push ebp
// 00560a71  8bec                 mov ebp, esp
// 00560a73  6aff                 push -1
// 00560a75  6848ed7c00           push 0x7ced48
// 00560a7a  64a100000000         mov eax, dword ptr fs:[0]
// 00560a80  50                   push eax
// 00560a81  64892500000000       mov dword ptr fs:[0], esp
// 00560a88  83ec0c               sub esp, 0xc
// 00560a8b  53                   push ebx
// 00560a8c  56                   push esi
// 00560a8d  57                   push edi
// 00560a8e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00560a91  8bf9                 mov edi, ecx
// 00560a93  6a04                 push 4
// 00560a95  897de8               mov dword ptr [ebp - 0x18], edi
// 00560a98  e883fe1300           call 0x6a0920
// 00560a9d  33c9                 xor ecx, ecx
// 00560a9f  83c404               add esp, 4
// 00560aa2  3bc1                 cmp eax, ecx
// 00560aa4  7404                 je 0x560aaa
// 00560aa6  8938                 mov dword ptr [eax], edi
// 00560aa8  eb02                 jmp 0x560aac
// 00560aaa  33c0                 xor eax, eax
// 00560aac  8907                 mov dword ptr [edi], eax
// 00560aae  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00560ab1  8b7310               mov esi, dword ptr [ebx + 0x10]
// 00560ab4  2b730c               sub esi, dword ptr [ebx + 0xc]
// 00560ab7  894dfc               mov dword ptr [ebp - 4], ecx
// 00560aba  c1fe05               sar esi, 5
// 00560abd  894f0c               mov dword ptr [edi + 0xc], ecx
// 00560ac0  894f10               mov dword ptr [edi + 0x10], ecx
// 00560ac3  894f14               mov dword ptr [edi + 0x14], ecx
// 00560ac6  3bf1                 cmp esi, ecx
// 00560ac8  746c                 je 0x560b36
// 00560aca  81feffffff07         cmp esi, 0x7ffffff
// 00560ad0  7605                 jbe 0x560ad7
// 00560ad2  e86962f6ff           call 0x4c6d40
// 00560ad7  51                   push ecx
// 00560ad8  56                   push esi
// 00560ad9  e852b8ffff           call 0x55c330
// 00560ade  c1e605               shl esi, 5
// 00560ae1  03f0                 add esi, eax
// 00560ae3  89470c               mov dword ptr [edi + 0xc], eax
// 00560ae6  894710               mov dword ptr [edi + 0x10], eax
// 00560ae9  897714               mov dword ptr [edi + 0x14], esi
// 00560aec  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00560aef  83c408               add esp, 8
// 00560af2  c645fc01             mov byte ptr [ebp - 4], 1
// 00560af6  8945ec               mov dword ptr [ebp - 0x14], eax
// 00560af9  39430c               cmp dword ptr [ebx + 0xc], eax
// 00560afc  7606                 jbe 0x560b04
// 00560afe  ff1590288000         call dword ptr [0x802890]
// 00560b04  8b730c               mov esi, dword ptr [ebx + 0xc]
// 00560b07  3b7310               cmp esi, dword ptr [ebx + 0x10]
// 00560b0a  7606                 jbe 0x560b12
// 00560b0c  ff1590288000         call dword ptr [0x802890]
// 00560b12  8b470c               mov eax, dword ptr [edi + 0xc]
// 00560b15  c6450800             mov byte ptr [ebp + 8], 0
// 00560b19  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00560b1c  8b5508               mov edx, dword ptr [ebp + 8]
// 00560b1f  51                   push ecx
// 00560b20  52                   push edx
// 00560b21  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00560b24  8d4f08               lea ecx, [edi + 8]
// 00560b27  51                   push ecx
// 00560b28  50                   push eax
// 00560b29  52                   push edx
// 00560b2a  56                   push esi
// 00560b2b  e8f0e1ffff           call 0x55ed20
// 00560b30  83c418               add esp, 0x18
// 00560b33  894710               mov dword ptr [edi + 0x10], eax
// 00560b36  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00560b39  8bc7                 mov eax, edi
// 00560b3b  5f                   pop edi
// 00560b3c  5e                   pop esi
// 00560b3d  64890d00000000       mov dword ptr fs:[0], ecx
// 00560b44  5b                   pop ebx
// 00560b45  8be5                 mov esp, ebp
// 00560b47  5d                   pop ebp
// 00560b48  c20400               ret 4
// standard library vector<pod32> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
