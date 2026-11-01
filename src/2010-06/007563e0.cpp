// from server: 100% by auto
// roc 2010-06 007563e0  unit: RBX::Block  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007563e0
//
// 007563e0  6aff                 push -1
// 007563e2  682bb29a00           push 0x9ab22b
// 007563e7  64a100000000         mov eax, dword ptr fs:[0]
// 007563ed  50                   push eax
// 007563ee  64892500000000       mov dword ptr fs:[0], esp
// 007563f5  83ec0c               sub esp, 0xc
// 007563f8  53                   push ebx
// 007563f9  56                   push esi
// 007563fa  57                   push edi
// 007563fb  8bf1                 mov esi, ecx
// 007563fd  6a04                 push 4
// 007563ff  89742418             mov dword ptr [esp + 0x18], esi
// 00756403  e898150500           call 0x7a79a0
// 00756408  33db                 xor ebx, ebx
// 0075640a  83c404               add esp, 4
// 0075640d  3bc3                 cmp eax, ebx
// 0075640f  7404                 je 0x756415
// 00756411  8930                 mov dword ptr [eax], esi
// 00756413  eb02                 jmp 0x756417
// 00756415  33c0                 xor eax, eax
// 00756417  8906                 mov dword ptr [esi], eax
// 00756419  895e0c               mov dword ptr [esi + 0xc], ebx
// 0075641c  895e10               mov dword ptr [esi + 0x10], ebx
// 0075641f  895e14               mov dword ptr [esi + 0x14], ebx
// 00756422  6a04                 push 4
// 00756424  c744242401000000     mov dword ptr [esp + 0x24], 1
// 0075642c  8d7e18               lea edi, [esi + 0x18]
// 0075642f  e86c150500           call 0x7a79a0
// 00756434  83c404               add esp, 4
// 00756437  3bc3                 cmp eax, ebx
// 00756439  7404                 je 0x75643f
// 0075643b  8938                 mov dword ptr [eax], edi
// 0075643d  eb02                 jmp 0x756441
// 0075643f  33c0                 xor eax, eax
// 00756441  8907                 mov dword ptr [edi], eax
// 00756443  895f0c               mov dword ptr [edi + 0xc], ebx
// 00756446  895f10               mov dword ptr [edi + 0x10], ebx
// 00756449  895f14               mov dword ptr [edi + 0x14], ebx
// 0075644c  6a04                 push 4
// 0075644e  c644242403           mov byte ptr [esp + 0x24], 3
// 00756453  8d7e30               lea edi, [esi + 0x30]
// 00756456  e845150500           call 0x7a79a0
// 0075645b  83c404               add esp, 4
// 0075645e  3bc3                 cmp eax, ebx
// 00756460  7404                 je 0x756466
// 00756462  8938                 mov dword ptr [eax], edi
// 00756464  eb02                 jmp 0x756468
// 00756466  33c0                 xor eax, eax
// 00756468  8907                 mov dword ptr [edi], eax
// 0075646a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0075646e  895f0c               mov dword ptr [edi + 0xc], ebx
// 00756471  895f10               mov dword ptr [edi + 0x10], ebx
// 00756474  895f14               mov dword ptr [edi + 0x14], ebx
// 00756477  5f                   pop edi
// 00756478  8bc6                 mov eax, esi
// 0075647a  5e                   pop esi
// 0075647b  5b                   pop ebx
// 0075647c  64890d00000000       mov dword ptr fs:[0], ecx
// 00756483  83c418               add esp, 0x18
// 00756486  c3                   ret 
// library ogre-1.7.0/OgreProgressiveMesh.cpp (function ??0PMWorkingData@ProgressiveMesh@Ogre@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreProgressiveMesh.cpp
