// from server: 100% by auto
// roc 2009-12 004ab420  unit: Ogre::RbxSceneUpdater  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ab420
//
// 004ab420  55                   push ebp
// 004ab421  8bec                 mov ebp, esp
// 004ab423  6aff                 push -1
// 004ab425  68d80b9300           push 0x930bd8
// 004ab42a  64a100000000         mov eax, dword ptr fs:[0]
// 004ab430  50                   push eax
// 004ab431  64892500000000       mov dword ptr fs:[0], esp
// 004ab438  83ec0c               sub esp, 0xc
// 004ab43b  53                   push ebx
// 004ab43c  56                   push esi
// 004ab43d  57                   push edi
// 004ab43e  8965f0               mov dword ptr [ebp - 0x10], esp
// 004ab441  8bf1                 mov esi, ecx
// 004ab443  6a04                 push 4
// 004ab445  8975e8               mov dword ptr [ebp - 0x18], esi
// 004ab448  e813843400           call 0x7f3860
// 004ab44d  33c9                 xor ecx, ecx
// 004ab44f  83c404               add esp, 4
// 004ab452  3bc1                 cmp eax, ecx
// 004ab454  7404                 je 0x4ab45a
// 004ab456  8930                 mov dword ptr [eax], esi
// 004ab458  eb02                 jmp 0x4ab45c
// 004ab45a  33c0                 xor eax, eax
// 004ab45c  8906                 mov dword ptr [esi], eax
// 004ab45e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004ab461  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 004ab464  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 004ab467  894dfc               mov dword ptr [ebp - 4], ecx
// 004ab46a  c1ff03               sar edi, 3
// 004ab46d  894e0c               mov dword ptr [esi + 0xc], ecx
// 004ab470  894e10               mov dword ptr [esi + 0x10], ecx
// 004ab473  894e14               mov dword ptr [esi + 0x14], ecx
// 004ab476  3bf9                 cmp edi, ecx
// 004ab478  746a                 je 0x4ab4e4
// 004ab47a  81ffffffff1f         cmp edi, 0x1fffffff
// 004ab480  7605                 jbe 0x4ab487
// 004ab482  e8d96cf9ff           call 0x442160
// 004ab487  51                   push ecx
// 004ab488  57                   push edi
// 004ab489  e842060d00           call 0x57bad0
// 004ab48e  89460c               mov dword ptr [esi + 0xc], eax
// 004ab491  894610               mov dword ptr [esi + 0x10], eax
// 004ab494  8d04f8               lea eax, [eax + edi*8]
// 004ab497  894614               mov dword ptr [esi + 0x14], eax
// 004ab49a  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004ab49d  83c408               add esp, 8
// 004ab4a0  c645fc01             mov byte ptr [ebp - 4], 1
// 004ab4a4  8945ec               mov dword ptr [ebp - 0x14], eax
// 004ab4a7  39430c               cmp dword ptr [ebx + 0xc], eax
// 004ab4aa  7606                 jbe 0x4ab4b2
// 004ab4ac  ff1560b79800         call dword ptr [0x98b760]
// 004ab4b2  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 004ab4b5  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 004ab4b8  7606                 jbe 0x4ab4c0
// 004ab4ba  ff1560b79800         call dword ptr [0x98b760]
// 004ab4c0  8b460c               mov eax, dword ptr [esi + 0xc]
// 004ab4c3  c6450800             mov byte ptr [ebp + 8], 0
// 004ab4c7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004ab4ca  8b5508               mov edx, dword ptr [ebp + 8]
// 004ab4cd  51                   push ecx
// 004ab4ce  52                   push edx
// 004ab4cf  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004ab4d2  8d4e08               lea ecx, [esi + 8]
// 004ab4d5  51                   push ecx
// 004ab4d6  50                   push eax
// 004ab4d7  52                   push edx
// 004ab4d8  57                   push edi
// 004ab4d9  e8f2f8ffff           call 0x4aadd0
// 004ab4de  83c418               add esp, 0x18
// 004ab4e1  894610               mov dword ptr [esi + 0x10], eax
// 004ab4e4  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004ab4e7  5f                   pop edi
// 004ab4e8  8bc6                 mov eax, esi
// 004ab4ea  5e                   pop esi
// 004ab4eb  64890d00000000       mov dword ptr fs:[0], ecx
// 004ab4f2  5b                   pop ebx
// 004ab4f3  8be5                 mov esp, ebp
// 004ab4f5  5d                   pop ebp
// 004ab4f6  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
