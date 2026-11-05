// from server: 100% by Yeetserama
// roc 2010-06 008d6c70  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 255 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d6c70
//
// 008d6c70  55                   push ebp
// 008d6c71  8bec                 mov ebp, esp
// 008d6c73  6aff                 push -1
// 008d6c75  68b8e59b00           push 0x9be5b8
// 008d6c7a  64a100000000         mov eax, dword ptr fs:[0]
// 008d6c80  50                   push eax
// 008d6c81  64892500000000       mov dword ptr fs:[0], esp
// 008d6c88  83ec0c               sub esp, 0xc
// 008d6c8b  53                   push ebx
// 008d6c8c  56                   push esi
// 008d6c8d  57                   push edi
// 008d6c8e  8965f0               mov dword ptr [ebp - 0x10], esp
// 008d6c91  8bf1                 mov esi, ecx
// 008d6c93  6a04                 push 4
// 008d6c95  8975e8               mov dword ptr [ebp - 0x18], esi
// 008d6c98  e8030dedff           call 0x7a79a0
// 008d6c9d  83c404               add esp, 4
// 008d6ca0  85c0                 test eax, eax
// 008d6ca2  7404                 je 0x8d6ca8
// 008d6ca4  8930                 mov dword ptr [eax], esi
// 008d6ca6  eb02                 jmp 0x8d6caa
// 008d6ca8  33c0                 xor eax, eax
// 008d6caa  8906                 mov dword ptr [esi], eax
// 008d6cac  8b5d08               mov ebx, dword ptr [ebp + 8]
// 008d6caf  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 008d6cb2  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 008d6cb5  b8310cc330           mov eax, 0x30c30c31
// 008d6cba  f7e9                 imul ecx
// 008d6cbc  c1fa04               sar edx, 4
// 008d6cbf  8bfa                 mov edi, edx
// 008d6cc1  b800000000           mov eax, 0
// 008d6cc6  c1ef1f               shr edi, 0x1f
// 008d6cc9  03fa                 add edi, edx
// 008d6ccb  c745fc00000000       mov dword ptr [ebp - 4], 0
// 008d6cd2  89460c               mov dword ptr [esi + 0xc], eax
// 008d6cd5  894610               mov dword ptr [esi + 0x10], eax
// 008d6cd8  894614               mov dword ptr [esi + 0x14], eax
// 008d6cdb  746c                 je 0x8d6d49
// 008d6cdd  81ffc3300c03         cmp edi, 0x30c30c3
// 008d6ce3  7605                 jbe 0x8d6cea
// 008d6ce5  e806d1b4ff           call 0x423df0
// 008d6cea  50                   push eax
// 008d6ceb  57                   push edi
// 008d6cec  e8bfe5ffff           call 0x8d52b0
// 008d6cf1  6bff54               imul edi, edi, 0x54
// 008d6cf4  03f8                 add edi, eax
// 008d6cf6  89460c               mov dword ptr [esi + 0xc], eax
// 008d6cf9  894610               mov dword ptr [esi + 0x10], eax
// 008d6cfc  897e14               mov dword ptr [esi + 0x14], edi
// 008d6cff  8b4310               mov eax, dword ptr [ebx + 0x10]
// 008d6d02  83c408               add esp, 8
// 008d6d05  c645fc01             mov byte ptr [ebp - 4], 1
// 008d6d09  8945ec               mov dword ptr [ebp - 0x14], eax
// 008d6d0c  39430c               cmp dword ptr [ebx + 0xc], eax
// 008d6d0f  7606                 jbe 0x8d6d17
// 008d6d11  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d6d17  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 008d6d1a  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 008d6d1d  7606                 jbe 0x8d6d25
// 008d6d1f  ff150ca99e00         call dword ptr [0x9ea90c]
// 008d6d25  8b460c               mov eax, dword ptr [esi + 0xc]
// 008d6d28  c6450800             mov byte ptr [ebp + 8], 0
// 008d6d2c  8b4d08               mov ecx, dword ptr [ebp + 8]
// 008d6d2f  8b5508               mov edx, dword ptr [ebp + 8]
// 008d6d32  51                   push ecx
// 008d6d33  52                   push edx
// 008d6d34  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 008d6d37  8d4e08               lea ecx, [esi + 8]
// 008d6d3a  51                   push ecx
// 008d6d3b  50                   push eax
// 008d6d3c  52                   push edx
// 008d6d3d  57                   push edi
// 008d6d3e  e8cdf4ffff           call 0x8d6210
// 008d6d43  83c418               add esp, 0x18
// 008d6d46  894610               mov dword ptr [esi + 0x10], eax
// 008d6d49  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008d6d4c  5f                   pop edi
// 008d6d4d  8bc6                 mov eax, esi
// 008d6d4f  5e                   pop esi
// 008d6d50  64890d00000000       mov dword ptr fs:[0], ecx
// 008d6d57  5b                   pop ebx
// 008d6d58  8be5                 mov esp, ebp
// 008d6d5a  5d                   pop ebp
// 008d6d5b  c20400               ret 4
// 008d6d5e  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 008d6d61  e80afbffff           call 0x8d6870
// 008d6d66  6a00                 push 0
// 008d6d68  6a00                 push 0
// 008d6d6a  e8431cedff           call 0x7a89b2
// copied from an identical function in another client (function ??0?$vector@V?$basic_option@D@program_options@boost@@V?$allocator@V?$basic_option@D@program_options@boost@@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.35.0-dll libs/program_options/src/cmdline.cpp