// from server: 100% by auto
// roc 2009-12 004ab6b0  unit: Ogre::RbxSceneUpdater  size: 267 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ab6b0
//
// 004ab6b0  56                   push esi
// 004ab6b1  57                   push edi
// 004ab6b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004ab6b6  8bf1                 mov esi, ecx
// 004ab6b8  3bf7                 cmp esi, edi
// 004ab6ba  0f84f4000000         je 0x4ab7b4
// 004ab6c0  53                   push ebx
// 004ab6c1  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 004ab6c4  55                   push ebp
// 004ab6c5  8b6f0c               mov ebp, dword ptr [edi + 0xc]
// 004ab6c8  8bcb                 mov ecx, ebx
// 004ab6ca  2bcd                 sub ecx, ebp
// 004ab6cc  c1f903               sar ecx, 3
// 004ab6cf  85c9                 test ecx, ecx
// 004ab6d1  7510                 jne 0x4ab6e3
// 004ab6d3  8bce                 mov ecx, esi
// 004ab6d5  e8a6feffff           call 0x4ab580
// 004ab6da  5d                   pop ebp
// 004ab6db  5b                   pop ebx
// 004ab6dc  5f                   pop edi
// 004ab6dd  8bc6                 mov eax, esi
// 004ab6df  5e                   pop esi
// 004ab6e0  c20400               ret 4
// 004ab6e3  8b5610               mov edx, dword ptr [esi + 0x10]
// 004ab6e6  8b460c               mov eax, dword ptr [esi + 0xc]
// 004ab6e9  2bd0                 sub edx, eax
// 004ab6eb  c1fa03               sar edx, 3
// 004ab6ee  3bca                 cmp ecx, edx
// 004ab6f0  7739                 ja 0x4ab72b
// 004ab6f2  50                   push eax
// 004ab6f3  53                   push ebx
// 004ab6f4  55                   push ebp
// 004ab6f5  e896f6ffff           call 0x4aad90
// 004ab6fa  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004ab6fe  51                   push ecx
// 004ab6ff  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004ab702  8d5608               lea edx, [esi + 8]
// 004ab705  52                   push edx
// 004ab706  51                   push ecx
// 004ab707  50                   push eax
// 004ab708  e823f7ffff           call 0x4aae30
// 004ab70d  8b5710               mov edx, dword ptr [edi + 0x10]
// 004ab710  2b570c               sub edx, dword ptr [edi + 0xc]
// 004ab713  8b460c               mov eax, dword ptr [esi + 0xc]
// 004ab716  83c41c               add esp, 0x1c
// 004ab719  5d                   pop ebp
// 004ab71a  c1fa03               sar edx, 3
// 004ab71d  5b                   pop ebx
// 004ab71e  8d0cd0               lea ecx, [eax + edx*8]
// 004ab721  5f                   pop edi
// 004ab722  894e10               mov dword ptr [esi + 0x10], ecx
// 004ab725  8bc6                 mov eax, esi
// 004ab727  5e                   pop esi
// 004ab728  c20400               ret 4
// 004ab72b  85c0                 test eax, eax
// 004ab72d  7504                 jne 0x4ab733
// 004ab72f  33db                 xor ebx, ebx
// 004ab731  eb08                 jmp 0x4ab73b
// 004ab733  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 004ab736  2bd8                 sub ebx, eax
// 004ab738  c1fb03               sar ebx, 3
// 004ab73b  3bcb                 cmp ecx, ebx
// 004ab73d  772c                 ja 0x4ab76b
// 004ab73f  8bcd                 mov ecx, ebp
// 004ab741  50                   push eax
// 004ab742  8d1cd1               lea ebx, [ecx + edx*8]
// 004ab745  53                   push ebx
// 004ab746  51                   push ecx
// 004ab747  e844f6ffff           call 0x4aad90
// 004ab74c  8b5610               mov edx, dword ptr [esi + 0x10]
// 004ab74f  8b4710               mov eax, dword ptr [edi + 0x10]
// 004ab752  83c40c               add esp, 0xc
// 004ab755  52                   push edx
// 004ab756  50                   push eax
// 004ab757  53                   push ebx
// 004ab758  8bce                 mov ecx, esi
// 004ab75a  e891fbffff           call 0x4ab2f0
// 004ab75f  5d                   pop ebp
// 004ab760  5b                   pop ebx
// 004ab761  894610               mov dword ptr [esi + 0x10], eax
// 004ab764  5f                   pop edi
// 004ab765  8bc6                 mov eax, esi
// 004ab767  5e                   pop esi
// 004ab768  c20400               ret 4
// 004ab76b  85c0                 test eax, eax
// 004ab76d  7418                 je 0x4ab787
// 004ab76f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004ab772  51                   push ecx
// 004ab773  50                   push eax
// 004ab774  8bce                 mov ecx, esi
// 004ab776  e8a5fbffff           call 0x4ab320
// 004ab77b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004ab77e  51                   push ecx
// 004ab77f  e8d6803400           call 0x7f385a
// 004ab784  83c404               add esp, 4
// 004ab787  8b4710               mov eax, dword ptr [edi + 0x10]
// 004ab78a  2b470c               sub eax, dword ptr [edi + 0xc]
// 004ab78d  8bce                 mov ecx, esi
// 004ab78f  c1f803               sar eax, 3
// 004ab792  50                   push eax
// 004ab793  e848121e00           call 0x68c9e0
// 004ab798  84c0                 test al, al
// 004ab79a  7416                 je 0x4ab7b2
// 004ab79c  8b560c               mov edx, dword ptr [esi + 0xc]
// 004ab79f  8b4710               mov eax, dword ptr [edi + 0x10]
// 004ab7a2  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004ab7a5  52                   push edx
// 004ab7a6  50                   push eax
// 004ab7a7  51                   push ecx
// 004ab7a8  8bce                 mov ecx, esi
// 004ab7aa  e841fbffff           call 0x4ab2f0
// 004ab7af  894610               mov dword ptr [esi + 0x10], eax
// 004ab7b2  5d                   pop ebp
// 004ab7b3  5b                   pop ebx
// 004ab7b4  5f                   pop edi
// 004ab7b5  8bc6                 mov eax, esi
// 004ab7b7  5e                   pop esi
// 004ab7b8  c20400               ret 4
// library templates-boost-1_34_1/vector_sp.cpp (function ??4?$vector@V?$shared_ptr@UT@@@boost@@V?$allocator@V?$shared_ptr@UT@@@boost@@@std@@@std@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_sp.cpp
